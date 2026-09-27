#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_STUDENTS = 5;
struct studentIFSPB
{
    char name[100];
    char class[50];
    int grade1;
    int grade2;
    int grade3;
    int mean;
};

void readData(char *buffer, int length)
{
    fgets(buffer, length, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
}
void registerStudent(struct studentIFSPB list[], int *cont)
{
    struct studentIFSPB data;
    printf("Name: ");
    readData(data.name, sizeof(data.name));
    printf("Class: ");
    readData(data.name, sizeof(data.name));
    printf("Grades 1, 2 and 3: ");
    scanf("%d%d%d", &data.grade1, &data.grade2, &data.grade3);
    data.mean = (data.grade1 + data.grade2 + data.grade3) / 3;

    list[*cont] = data;
    (*cont)++;

    printf("Registration ended!\n");
}
void removeStudent(struct studentIFSPB list[], int *cont, char name[100], char class[50])
{
    int index = -1;
    for (int i = 0; i < cont; i++)
    {
        if (list[i].name == name && list[i].class == class)
            index = i;
        break;
    }
    if (index = -1)
        printf("Not founded\n");

    list[index] = list[index + 1];
    (*cont)--;

    printf("Student removed!\n");
}
void printStudents(struct studentIFSPB list[], int *cont)
{
    printf("\n========== STUDENTS ==========");
    for (int i = 0; i < *cont; i++)
    {
        printf("\n---------- STUDENT %d ----------\n", i + 1);
        printf("| Name: %s\n", list[i].name);
        printf("| Class: %s\n", list[i].class);
        printf("| Grade 1: %d\n", list[i].grade1);
        printf("| Grade 2: %d\n", list[i].grade2);
        printf("| Grade 3: %d\n", list[i].grade3);
        printf("| Mean: %d\n", list[i].mean);
        printf("\n");
    }
}
int main()
{
    int cont = 0, option = 1;
    struct studentIFSPB *list;
    while (option)
    {
        printf("\n========== MENU ==========\n1 - Register Student\n2 - Delete Student\n3 - Print Student\n\nAny Key - Exit\n\n");
        scanf("%d", &option);
        getchar();
        if (option == 1)
        {
            registerStudent(&list, &cont);
        }
        else if (option == 2)
        {
            char name[100], studentClass[50];
            printf("Student name: ");
            readData(name, sizeof(name));
            printf("Student class: ");
            readData(studentClass, sizeof(studentClass));
            removeStudent(&list, &cont, name, studentClass);
        }
        else if (option == 3)
        {
            printStudents(&list, &cont);
        }
        else
            break;
    }
}