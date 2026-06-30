#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include "../include/parser.h"
#include "../include/analytics.h"

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc != 2)
    {
        if (rank == 0)
            printf("Usage: %s <logfile>\n", argv[0]);

        MPI_Finalize();
        return 1;
    }

    long filesize = 0;

    if (rank == 0)
    {
        FILE *fp = fopen(argv[1], "rb");

        if (fp == NULL)
        {
            perror("Error opening file");
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        fseek(fp, 0, SEEK_END);
        filesize = ftell(fp);
        fclose(fp);
    }

    /* Broadcast file size to all ranks */
    MPI_Bcast(&filesize, 1, MPI_LONG, 0, MPI_COMM_WORLD);

    /* Compute chunk for each rank */
    long chunk = filesize / size;

    long start_pos = rank * chunk;
    long end_pos = (rank == size - 1) ? filesize : (rank + 1) * chunk;

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL)
    {
        perror("Error opening file");
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    /* Move to assigned chunk */
    fseek(file, start_pos, SEEK_SET);

    /* Skip partial line (except rank 0) */
    if (start_pos != 0)
    {
        fseek(file, start_pos - 1, SEEK_SET);

        if (fgetc(file) != '\n')
        {
            char dummy[2048];
            fgets(dummy, sizeof(dummy), file);
        }
    }

    Analytics local;
    analytics_init(&local);

    char line[2048];
    LogEntry entry;

    /* Synchronize before timing */
    MPI_Barrier(MPI_COMM_WORLD);

    double start = MPI_Wtime();

    while (ftell(file) < end_pos && fgets(line, sizeof(line), file))
    {
        if (parse_log_line(line, &entry))
            analytics_update(&local, &entry);
    }

    fclose(file);

    Analytics global;

    MPI_Reduce(&local.parsed_lines,
               &global.parsed_lines,
               9,
               MPI_LONG,
               MPI_SUM,
               0,
               MPI_COMM_WORLD);

    double end = MPI_Wtime();

    if (rank == 0)
    {
        analytics_print(&global, end - start);
    }

    MPI_Finalize();

    return 0;
}
