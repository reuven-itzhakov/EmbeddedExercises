#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
    int fd;
    const char *write_data = "Hello, Kernel Module!";
    char read_data[100] = {0};
    size_t len = strlen(write_data);
    ssize_t bytes_written;
    ssize_t bytes_read;

    fd = open("/dev/my_module", O_WRONLY);
    if(fd < 0){
        perror("Failed to open /dev/my_module");
        return 1;
    }
    printf("Opened /dev/my_module successfully\n");

    bytes_written = write(fd, write_data, len);
    if(bytes_written < 0){
        perror("Failed to write to /dev/my_module");
        close(fd);
        return 1;
    }
    printf("Wrote %zd bytes to /dev/my_module: %s\n", bytes_written, write_data);

    close(fd);
    printf("Closed /dev/my_module successfully\n");

    fd = open("/dev/my_module", O_RDONLY);
    if(fd < 0){
        perror("Failed to open /dev/my_module");
        return 1;
    }
    printf("Opened /dev/my_module successfully\n");

    bytes_read = read(fd, read_data, sizeof(read_data) - 1);
    if(bytes_read < 0){
        perror("Failed to read from /dev/my_module");
        close(fd);
        return 1;
    }
    printf("Read %zd bytes from /dev/my_module: %s\n", bytes_read, read_data);

    close(fd);
    printf("Closed /dev/my_module successfully\n");

    return 0;
}