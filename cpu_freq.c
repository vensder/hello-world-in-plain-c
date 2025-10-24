#include <stdio.h>
#include <stdlib.h>  /* For atof() */
#include <string.h>  /* For strstr(), strtok() */

int cpu_freq(void)
{
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp) {
        printf("Error: Unable to read /proc/cpuinfo\n");
        return 1;
    }

    char line[256];
    int core_id = -1;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "processor")) {
            char *token = strtok(line, ":");
            if (token) {
                token = strtok(NULL, ":");
                if (token) {
                    core_id = atoi(token);  /* Get core ID */
                }
            }
        } else if (strstr(line, "cpu MHz")) {
            char *token = strtok(line, ":");
            if (token) {
                token = strtok(NULL, ":");
                if (token && core_id >= 0) {
                    double freq = atof(token);
                    printf("Core %d: %.2f MHz\n", core_id, freq);
                }
            }
        }
    }

    fclose(fp);

    return 0;
}
