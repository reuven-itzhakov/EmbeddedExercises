#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    
    char *filename = "/etc/passwd";

    struct stat st;
    if(stat(filename, &st) == -1){
        perror("stat");
        return 1;
    }

    // Display the file size, similar to how 'ls -s' would show it
    printf("%ld %s\n", (st.st_blocks * 512 + 1023) / 1024, filename);

    // Display the content of the file
    int fd = open(filename, O_RDONLY);
    if(fd == -1){
        perror("open");
        return 1;
    }
    
    char buffer[1024];
    int bytes_read;
    
    while((bytes_read = read(fd, buffer, sizeof(buffer))) > 0){
        if(write(STDOUT_FILENO, buffer, bytes_read) == -1){
            perror("write");
            return 1;
        }
    }   

    return 0;
}