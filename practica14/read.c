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

    if (student_index<0 || student_index>9){
        printf("Index out of range 0<id<9 id: %d\n", student_index);
        return 1;
    }

    Student *myStudent1;
    myStudent1 = (Student *) malloc(sizeof(Student));

    src = open("class.bin", O_RDONLY);

    pread(src, myStudent1, sizeof(Student), sizeof(Student)*student_index);
    printf("My student is: id:%d, semester:%d, %s, %s\n", myStudent1->id, myStudent1->semester, myStudent1->firstName, myStudent1->lastName);
   // lseek(src, -sizeof(Student), SEEK_CUR);
    close(src);
    free(myStudent1);
    return 0;
}