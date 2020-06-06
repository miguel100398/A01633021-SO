#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define total_students 10

typedef struct s {
    unsigned char id;
    unsigned char semester;
    char firstName[20];
    char lastName[20];
} Student;

int main(){
    int destination;

    Student *myStudents[total_students];
    destination = creat("class.bin", 0600);
    for (int i = 0; i<total_students; i++){
        myStudents[i] = (Student *) malloc(sizeof(Student));
        myStudents[i]->id = i;
        myStudents[i]->semester = 8;
        sprintf(myStudents[i]->firstName, "%s", "Miguel");
        sprintf(myStudents[i]->lastName, "%s_%d", "Bucio", i );
        write(destination, myStudents[i], sizeof(Student));
        free(myStudents[i]);
    }
    close(destination);
    return 0;
}