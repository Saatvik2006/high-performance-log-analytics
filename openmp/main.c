#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#include "../include/parser.h"
#include "../include/timer.h"
#include "../include/analytics.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    double start = get_time();

    Analytics global_stats;
    analytics_init(&global_stats);

#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int threads = omp_get_num_threads();

        FILE *file = fopen(argv[1], "rb");

        if (file)
        {
            fseek(file, 0, SEEK_END);
            long filesize = ftell(file);

            long chunk = filesize / threads;

            long start_pos = tid * chunk;
            long end_pos = (tid == threads - 1) ? filesize : (tid + 1) * chunk;

            fseek(file, start_pos, SEEK_SET);

            if (start_pos != 0)
            {
                fseek(file, start_pos - 1, SEEK_SET);

                if (fgetc(file) != '\n')
                {
                    char dummy[2048];
                    fgets(dummy, sizeof(dummy), file);
                }
            }

            char line[2048];
            LogEntry entry;

            Analytics local_stats;
            analytics_init(&local_stats);

            while (ftell(file) < end_pos && fgets(line, sizeof(line), file))
            {
                if (parse_log_line(line, &entry))
                    analytics_update(&local_stats, &entry);
            }

            fclose(file);

#pragma omp critical
            {
                analytics_merge(&global_stats, &local_stats);
            }
        }
    }

    double runtime = get_time() - start;

    analytics_print(&global_stats, runtime);

    return 0;
}
