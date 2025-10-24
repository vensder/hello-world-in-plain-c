#include <stdio.h>
#include <string.h>

int sys_vendor(void)
{
    FILE *fp = fopen("/sys/class/dmi/id/sys_vendor", "r");
    if (!fp) {
        printf("Vendor: Bare metal or unknown (no DMI data)\n");
        return 0;
    }

    char vendor[256];
    if (fgets(vendor, sizeof(vendor), fp)) {
        vendor[strcspn(vendor, "\n")] = '\0';  /* Trim newline */
        if (strstr(vendor, "Microsoft")) {
            printf("Vendor: Hyper-V\n");
        } else if (strstr(vendor, "VMware")) {
            printf("Vendor: VMware\n");
        } else if (strstr(vendor, "innotek") || strstr(vendor, "Oracle")) {
            printf("Vendor: VirtualBox\n");
        } else if (strstr(vendor, "QEMU")) {
            printf("Vendor: QEMU/KVM\n");
        } else if (strstr(vendor, "Xen")) {
            printf("Vendor: Xen\n");
        } else {
            printf("Vendor: %s\n", vendor);  /* Bare metal or unknown VM */
        }
    } else {
        printf("Vendor: Unknown (no vendor data)\n");
    }

    fclose(fp);
    return 0;
}
