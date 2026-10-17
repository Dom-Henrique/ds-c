#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_EMPLOYEES = 15;

typedef struct enterpriseEmplies
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
} EnterpriseEmplies;
// it's necessary to have a structure for nodes
typedef struct node
{
    EnterpriseEmplies data;
    Node *next;
} Node;
typedef struct list
{
    Node *head;
    Node *tail;
    int size;
} List;
// i need to storage 15 emplies inside a vector.
void listInit(List *l)
{
    l->head = l->tail = NULL; // all tails and head initialize NULLED
    l->size = 0;
}
List insertSorted(List *l, EnterpriseEmplies e)
{
    Node *n = malloc(sizeof(Node));
    if (!n)
        return *l;
    n->data = e;
    n->next = NULL;

    Node *prev = NULL, *cur = l->head;
    while (cur && strcmp(cur->data.name, e.name) <= 0)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev == NULL)
    {
        n->next = l->head;
        l->head = n;
    }
    else
    {
        prev->next = n;
        n->next = cur;
    }
    if (cur == NULL)
        l->tail = n;
    l->size++;
    return *l;
}
int remove_by_name(List *l, const char *name) {
    Node *prev = NULL, *cur = l->head;
    while (cur && strcmp(cur->data.name, name) != 0) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) return 0;

    if (prev) prev->next = cur->next;
    else      l->head = cur->next;

    if (cur == l->tail) l->tail = prev;

    free(cur);
    l->size--;
    return 1;
}

void print_list(const List *l) {
    for (Node *p = l->head; p; p = p->next)
        printf("%s | %s | %d\n", p->data.name, p->data.address);
}

void list_free(List *l) {
    Node *cur = l->head;
    while (cur) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
    l->head = l->tail = NULL;
    l->size = 0;
}
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
