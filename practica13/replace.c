#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void replace_word(int tmp, char *word,char *searchWord,char *replaceWord, char *character);

int main(int argn,char **argv){
    char *fileName = argv[3];
    char *searchWord = argv[1];
    char *replaceWord = argv[2];
    char *tmpFileName = "/tmp/replace.txt";
    char *tmpnewFile = "/tmp/new_file.txt";
    char word[100];
    int i = 0;
    char character;
    int fd = open(fileName, O_RDONLY);
    int tmp = open(tmpFileName,O_WRONLY|O_CREAT,0600);
    if(fd < 0) {
        printf("No se puede abrir \n");
        exit(1);
    }
    while(read(fd,&character,1)){
        if((character == ' ' || character == '\n')) {
            word[i++] = character;
            word[i] = '\0';
            i = 0;
            replace_word(tmp, word, searchWord, replaceWord, &character);
        } else if(character != ' ' && character != '\n') {
        word[i++] = character;
        }
    }
    word[i] = '\0';
    character = 0x05; //END OF FILE
    replace_word(tmp, word, searchWord, replaceWord, &character);
    close(fd);
    close(tmp);
    //Renombrar archivo
    unlink(fileName);   //Borrar original
    //link(tmpFileName, fileName);    //Crear Alias
    link(tmpFileName, tmpnewFile);    //Crear archivo en tmp porque no se puede en workspace
    unlink(tmpFileName);    //Borrar temporal
    exit(0);
}


void replace_word(int tmp, char *word,char *searchWord,char *replaceWord, char *character){
    if( strncmp(word,searchWord,strlen(searchWord)) == 0){
        write(tmp,replaceWord,strlen(replaceWord));
        write(tmp,character, 1);
    } else {
        write(tmp,word,strlen(word));
    }
}