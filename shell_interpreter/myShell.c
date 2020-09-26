#ifndef MYSHELL_C
#define MYSHELL_C
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80
#define MAX_NUM_ARGS 4

size_t string_parser(char *input, char *word_array[]){
    size_t n =0;
    while (*input) {
        while (isspace((unsigned char)*input))
        ++input;
        if (*input) {
            word_array[n++] =  (char *) input;
            while (*input && !isspace((unsigned char)*input))
            ++input;
            *(input) = '\0';
            ++input;
        }
    }
    word_array[n] = NULL;
    return n;
}

int main(void){
    char *args[MAX_NUM_ARGS+1]; //Maximum number of arguments to be accepted
    char line[MAX_LINE+1];
    int should_run = 1;

    int i;
    while (should_run){
        printf("mish> ");
        fgets(line, MAX_LINE,stdin);    //Get String from command prompt
        line[strcspn(line, "\n")] = '\0';
        i = string_parser(line, args);
        //exit
        if ((strcmp(args[0], "exit"))==0){
            printf("Thanks for using myShell!\n");
            should_run = 0;     //Exit program
        }else{
            int pid = fork();   //Clone process
            if (pid) {  //Parent process
                wait(NULL); //Waits child finishes its execution
            }else{  //child process
                if (execvp(args[0], args)){     //Execute program
                    //Error executing program
                    printf("Program can´t be executed \n");
                }
                should_run = 0; //Finishes child process if program wasn´t executed
            }
        }

        fflush(stdout);
        fflush(stdin);
        line[0] = '\0';
        //clear args
        for (int i=0; i<MAX_NUM_ARGS+1;i++){
            args[i] = NULL;
        }
    }
    return 0;
}

#endif //MYSHELL_C