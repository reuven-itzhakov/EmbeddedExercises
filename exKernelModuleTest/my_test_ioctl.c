#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "my_ioctl.h"

#define DEVICE_PATH "/dev/my_module"

int main(void)
{
    int fd;
    struct my_driver_stats stats;

    fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open device");
        return EXIT_FAILURE;
    }
    close(fd);

    fd = open(DEVICE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Failed to open device");
        return EXIT_FAILURE;
    }

    if (ioctl(fd, MY_IOC_GET_STATS, &stats) < 0) {
        perror("MY_IOC_GET_STATS failed");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Before clear -> Total opens: %d, Total closes: %d\n",
           stats.total_opens, stats.total_closes);

    if (ioctl(fd, MY_IOC_CLEAR_STATS) < 0) {
        perror("MY_IOC_CLEAR_STATS failed");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("Statistics cleared.\n");

    if (ioctl(fd, MY_IOC_GET_STATS, &stats) < 0) {
        perror("MY_IOC_GET_STATS failed");
        close(fd);
        return EXIT_FAILURE;
    }
    printf("After clear  -> Total opens: %d, Total closes: %d\n",
           stats.total_opens, stats.total_closes);

    close(fd);
    return EXIT_SUCCESS;
}