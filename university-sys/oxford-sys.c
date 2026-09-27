#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_STUDENTS_PER_COURSE 40
#define MAX_STUDENTS 50
#define MAX_COURSES 10
/*
system for a small university department using vectors, 2d matrices and structs.
REQUIREMENTS:
- structs for students, course and departments
- register and remove function beyond of
*/

struct Student
{
    int id;
    char name[100];
    int year;
    int grades[6];
};
struct Course
{
    int courseCode;
    char title[30];
    int capacity;
    int studentsIDs[MAX_STUDENTS_PER_COURSE];
};
struct Department
{
    struct Student students[MAX_STUDENTS];
    struct Course courses[MAX_COURSES];
};
void readData(char *buffer[], int length)
{
    fgets(buffer, length, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
}
void addStudent(struct Student list[], int *cont)
{
    struct Student data;
    srand(time(NULL));
    data.id = rand() % 10;
    printf("Name: ");
    readData(data.name, sizeof(data.name));
    printf("Year: ");
    scanf("%d", data.year);
    // printf("Grades: ");
    for (int i = 0; i < sizeof(data.grades); i++)
    {
        printf("Grade %d", i + 1);
        scanf("%d", &data.grades[i]);
    }
    list[*cont] = data;
    (*cont)++;

    printf("Student registred!");
}
void addCourse(struct Course list[], int *cont)
{
    struct Course data;
    srand(time(NULL));
    data.courseCode = rand() % 7;
    printf("Course title: ");
    readData(data.title, sizeof(data.title));
    printf("Capacity: ");
    scanf("%d", data.capacity);

    printf("Course registred!\n");
}