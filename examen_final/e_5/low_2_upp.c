#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void replace_word(int tmp, char *word,char *searchWord,char *replaceWord, char *character);

int main(int argn,char **argv){
    char *fileName = argv[1];
    char *tmpFileName = "/tmp/replace.txt";
    char *tmpnewFile = "/tmp/new_file.txt";
    //Bandera para saber si es una ñ
    char flag_n;                
    unsigned char character;
    int fd = open(fileName, O_RDONLY);
    int tmp = open(tmpFileName,O_WRONLY|O_CREAT,0600);
    if(fd < 0) {
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd,&character,1)){
        //Revisar que sea minuscula (a-z) (97-122)
        if((character >= 'a' && character <= 'z')) {
            character = character - 32;
        //caso para ñ
        //se manda como 2 caracteres, primero 195 y luego un 177 para ñ y un 145 para Ñ
        } else if(character == 195){                
            flag_n = 1;             //Activar bandera de ñ
        } else if (flag_n && character == 177){     //codigo auxiliar de ñ
            character = 145;        //Codigo auxiliar de Ñ
            flag_n = 0;
        } else {
            flag_n = 0;
        }
        write(tmp,&character, 1);       //Escribir caracter en temporal
    }
    close(fd);
    close(tmp);
    //Renombrar archivo
    unlink(fileName);   //Borrar original
    //link(tmpFileName, fileName);    //Crear Alias
    link(tmpFileName, tmpnewFile);    //Crear archivo en tmp porque no se puede en workspace
    unlink(tmpFileName);    //Borrar temporal
    exit(0);
}