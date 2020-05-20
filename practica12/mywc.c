#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argn, char **argv){
    char *filename = argv[1];
    char buffer;
    unsigned int caracteres = 0;
    unsigned int palabras = 0;
    unsigned int lineas = 0;
    unsigned char f_palabra = 1;
    int fd = open(filename, O_RDONLY);

    if (fd<0){
        printf("No se puede abrir el archivo");
        exit(1);
    }

    while (read(fd, &buffer, 1)) {
        caracteres ++;
        if (buffer == '\n'){
            lineas ++;
            f_palabra = 1; 
        }
        else if (buffer == ' '){
            f_palabra = 1;
        }
        else if (f_palabra == 1){
            f_palabra = 0;
            palabras ++;
        }
    }
    printf(" caracteres: %d\n palabras: %d\n lineas: %d\n", caracteres, palabras, lineas);
    close(0);
    exit(0);
}