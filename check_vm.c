/* check_vm.c */
#include <stdio.h>
#include <string.h>

int check_vm(void)
{
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp) {
        printf("VM Status: Unable to read /proc/cpuinfo\n");
        return 1;
    }

    char line[256];
    int is_vm = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "flags") && strstr(line, "hypervisor")) {
            is_vm = 1;
            break;
        }
    }

    fclose(fp);

    if (is_vm) {
        printf("VM Status: Running on a virtual machine\n");
    } else {
        printf("VM Status: Running on bare metal\n");
    }

    return 0;
}
