#include <stdio.h>
#include <stdlib.h>

#include "../include/parser.h"
#include "../include/timer.h"
#include "../include/analytics.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: %s <logfile>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    if(!fp)
    {
        perror("Error opening file");
        return 1;
    }

    Analytics stats;
    analytics_init(&stats);

    char line[2048];
    LogEntry entry;

    double start = get_time();

    while(fgets(line,sizeof(line),fp))
    {
        if(parse_log_line(line,&entry))
            analytics_update(&stats,&entry);
    }

    double runtime = get_time() - start;

    fclose(fp);

    analytics_print(&stats,runtime);

    return 0;
}
