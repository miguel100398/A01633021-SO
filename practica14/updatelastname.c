#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct s {
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main(int argn,char **argv){
    int src;
    int student_index = atoi(argv[1]);
    char *replace = argv[2];

    if (student_index<0 || student_index>9){
        printf("Index out of range 0<id<9 id: %d\n", student_index);
        return 1;
    }

    Student *myStudent1;
    myStudent1 = (Student *) malloc(sizeof(Student));

    src = open("class.bin", O_RDWR);
    pread(src, myStudent1, sizeof(Student), sizeof(Student)*student_index);
    sprintf(myStudent1->lastName, "%s", replace);
    for (int i=strlen(myStudent1->lastName); i<20; i++){
        myStudent1->lastName[i] = '\0';
    }
    lseek(src, sizeof(Student)*student_index, SEEK_SET);
    write(src, myStudent1, sizeof(Student));
    close(src);
    free(myStudent1);
    return 0;
}