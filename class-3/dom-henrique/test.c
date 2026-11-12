#include <stdio.h>
const int times = 15;

struct enterpriseEmplies
{
    char name[50];
    char address[100];
    char birthDate[10];
    char education[20];
    char maritalStatus[10];
    char occupation[30];
    char admissionDate[30];
    int cpf;
};
// i need to storage 15 emplies inside a vector.
/*
REQUIRED FUNCTIONS:
- createVector
- addEmply
- removeEmply
- printEmply
*/
void createVector()
{
    struct enterpriseEmplies emplyees[15];
}
void addEmply(struct enterpriseEmplies)
{
    // localizar um espaço de armazenamento
}
void removeEmply(struct enterpriseEmplies)
{
}

int main()
{
    int option;
    struct enterpriseEmplies data;
    printf("========== MENU ==========\n1 - Create vector\n2 - Add emply\n3 - Remove emply\n4 - Print Emply\nAny key - Exit\n");
    scanf("%d", &option);
    if (option == 1)
    {
        createVector();
    }
    else if (option == 2)
    {
        char name[50];
        char address[100];
        char birthDate[10];
        char education[20];
        char maritalStatus[10];
        char occupation[30];
        char admissionDate[30];
        int cpf;
        printf("Name: ");
        scanf(" %c", &name);
        printf("Address: ");
        scanf(" %c", &address);
        printf("Birth Date: ");
        scanf(" %c", &birthDate);
        printf("Education: ");
        scanf(" %c", &education);
        printf("Marital Status: ");
        scanf(" %c", &maritalStatus);
        printf("Occupation: ");
        scanf(" %c", &occupation);
        printf("Admission Date: ");
        scanf(" %c", &admissionDate);
        printf("CPF: ");
        scanf(" %d", &cpf);
        data.name = name;
        data.address = address;
        data.birthDate = birthDate;
        data.education = education;
        data.maritalStatus = maritalStatus;
        data.occupation = occupation;
        data.admissionDate = admissionDate;
        data.cpf = cpf;

        addEmply(data);
    }
    else if (option == 3){
        removeEmply(data);
    }
    else if (option == 4){
        for (int i=0;i<data.length;i++){
            printf("%d", data[i]);
        }
    }
    else{
        break;
    }
}