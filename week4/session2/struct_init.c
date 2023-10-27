#include <stdio.h>
#include <string.h>

struct student{
    char name[20];
    char student_id[11];
    unsigned mark;
};

int main(){
    struct student new_student = {"Shay O'Donnell","29843848739", 35};
    strcpy(new_student.name, "Deborah O'Donnell");
    strcpy(new_student.student_id,"1238234345");
    printf("Student name: %s\n", new_student.name);
    printf("Student ID: %s\n", new_student.student_id);
    printf("Final mark: %u\n", new_student.mark);
    return 0;
}