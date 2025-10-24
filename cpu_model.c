#include <stdio.h>
#include <string.h>  /* For strstr(), strtok() */

int cpu_model(void)
{
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp) {
        printf("Error: Unable to read /proc/cpuinfo\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "model name")) {
            char *token = strtok(line, ":");
            if (token) {
                token = strtok(NULL, ":");
                if (token) {
                    /* Remove leading/trailing whitespace */
                    while (*token == ' ') token++;
                    char *end = token + strlen(token) - 1;
                    while (end > token && (*end == '\n' || *end == ' ')) *end-- = '\0';
                    printf("Model Name: %s\n", token);
                    fclose(fp);
                    return 0;
                }
            }
        }
    }

    fclose(fp);
    printf("Model Name: Not found\n");
    return 0;
}
