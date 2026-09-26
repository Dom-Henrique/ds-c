#include <stdio.h>
#include <string.h>
const int MAX_EMPLOYEES = 15;

struct enterpriseEmplies
{
    char name[50];
    char address[100];
    char birthDate[11];
    char education[20];
    char maritalStatus[10];
    char occupation[30];
    char admissionDate[11];
    float salary;
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
void readData(char *buffer, int length)
{
    /*
    buffer eh o array que armazena os caracteres
    length eh o tamanho do texto
    */
    fgets(buffer, length, stdin);
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n')
        buffer[len - 1] = '\0';
}
// sempre iremos chamar o struct para fazer qualquer coisa
void addEmply(struct enterpriseEmplies list[], int *cont)
{
    struct enterpriseEmplies data;
    printf("Name: ");
    readData(data.name, sizeof(data.name)); // o sizeof serve pra pegar o tamanho maximo
    printf("Address: ");
    readData(data.address, sizeof(data.address));
    printf("Birth Date: ");
    readData(data.birthDate, sizeof(data.birthDate));
    printf("Education: ");
    readData(data.education, sizeof(data.education));
    printf("Marital Status: ");
    readData(data.maritalStatus, sizeof(data.maritalStatus));
    printf("Occupation: ");
    readData(data.occupation, sizeof(data.occupation));
    printf("Admission Date: ");
    readData(data.admissionDate, sizeof(data.admissionDate));
    printf("CPF: ");
    scanf("%d", &data.cpf);
    printf("Salary: ");
    scanf("%f", &data.salary);

    // aqui ela vai armazenar tudo
    list[*cont] = data;
    (*cont)++; // serve pra nao vazar o tamanho definido

    printf("Sucessful emply addition!\n");
}
void removeEmply(struct enterpriseEmplies list[], int *cont, int cpf)
{
    int index = -1;
    for (int i = 0; i < *cont; i++)
    {
        if (list[i].cpf == cpf)
        {
            index = i;
        }
    }
    if (index == -1)
    {
        printf("Usuario nao existe!\n");
    }
    list[index] = list[index + 1];
    (*cont)--;
}
void printEmployees(struct enterpriseEmplies list[], int *cont)
{
    for (int i = 0; i < cont; i++)
    {
        printf("\n--- Emply %dth ---\n", i + 1);
        printf("Name: %s\n", list[i].name);
        printf("Address: %s\n", list[i].address);
        printf("Birth Date: %s\n", list[i].birthDate);
        printf("Education: %s\n", list[i].education);
        printf("Marital Status: %s\n", list[i].maritalStatus);
        printf("Occupation: %s\n", list[i].occupation);
        printf("Admission Date: %s\n", list[i].admissionDate);
        printf("CPF: %d\n", list[i].cpf);
        printf("Salary: %.2f\n", list[i].salary);
    }
}
struct enterpriseEmplies *createVector()
{
    struct enterpriseEmplies *data = malloc(MAX_EMPLOYEES * sizeof(struct enterpriseEmplies));
    if (data == NULL)
        return NULL;
    return data;
}
int main()
{
    int option = 1, cont = 0;
    struct enterpriseEmplies data = *createVector();
    while (option)
    {
        printf("========== MENU ==========\n1 - Add emply\n2 - Remove emply\n3 - Print Emply\nAny key - Exit\n");
        scanf("%d", &option);
        getchar();
        if (option == 1)
        {
            addEmply(&data, &cont);
        }
        else if (option == 2)
        {
            int cpf;
            printf("CPF of emply: ");
            scanf("%d", &cpf);
            removeEmply(&data, &cont, cpf);
        }
        else if (option == 3)
        {
            printEmployees;
        }
        else
        {
            break;
        }
    }
}