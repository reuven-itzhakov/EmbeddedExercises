#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){
    
    umask(000);

    int fd1 = creat("file1", 0777);
    if(fd1 == -1){
        perror("creat file1");
        return 1;
    }

    umask(007);

    int fd2 = creat("file2", 0777);
    if(fd2 == -1){
        perror("creat file2");
        return 1;
    }

}