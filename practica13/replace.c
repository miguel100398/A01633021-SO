#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argn, char **argv){
    char *filename = argv[3];
    char *searchWord = argv[1];
    char *replaceWord = argv[2];
    char word[100];
    char character;
    char espacio = 0;
    int i = 0;
    int fd = open(filename, O_RDONLY);

    if (fd<0){
        printf("No se puede abrir el archivo");
        exit(1);
    }

    while (read(fd, &character, 1)) {
        if ((character == ' ' || character == '\n' ) && espacio ==0 ){
            espacio = 1;
            word[i] = '\0';
            i = 0;
            if (strcmp(word, searchWord)==0){
                printf ("%s \n", replaceWord);
            }else {
                printf("%s \n", word);
            }
        }
        else if (character != ' ' && character != '\n' ){
            espacio = 0;
            word[i++] = character;
        }
       
    }

    close(fd);
    exit(0);
}