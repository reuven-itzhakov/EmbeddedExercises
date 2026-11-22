#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
    int fd1, fd2;

    fd1 = open("/dev/my_module", O_RDWR);
    if(fd1 < 0){
        perror("Failed to open /dev/my_module");
        return 1;
    }
    printf("1: Opened /dev/my_module successfully\n");


    fd2 = open("/dev/my_module", O_RDWR);
    if(fd2 < 0){
        perror("Failed to open /dev/my_module");
        close(fd1);
        return 1;
    }
    printf("2: Opened /dev/my_module successfully\n");


    close(fd1);
    printf("1: Closed /dev/my_module successfully\n");

    close(fd2);
    printf("2: Closed /dev/my_module successfully\n");
    
    return 0;
}