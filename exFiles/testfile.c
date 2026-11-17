#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    int fd = creat("testfile", 0777);
    if(fd == -1){
        perror("creat");
        return 1;
    }
    
    int lsk = lseek(fd, 1023, SEEK_SET);
    if(lsk == -1){
        perror("lseek");
        return 1;
    }

    write(fd, "X", 1);

    return 0;
}