// open,read,write,lseek,close
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fd = open("blus", O_RDWR | O_CREAT | O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        return -1;
    }
    const char* str = "Linux so easy!";
    write(fd, str, strlen(str));
    lseek(fd, 0, SEEK_SET);
    char* buf = (char*)malloc(strlen(str) + 1);
    read(fd, buf, strlen(str));
    printf("%s\n", buf);
    close(fd);
    free(buf);
    return 0;
}