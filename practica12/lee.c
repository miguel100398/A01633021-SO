#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argn, char **argv){
    char *filename = argv[1];
    char buffer;
    int fd = open(filename, O_RDONLY);

    if (fd<0){
        printf("No se puede abrir el archivo");
        exit(1);
    }

    while (read(fd, &buffer, 1)) {
        printf("%c", buffer);
    }
    close(0);
    exit(0);
}