#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#define MAX 15

struct pessoa
{
    char nome[100];
    char caractere[100];
};
struct fila
{
    int inicio;
    int fim;
    Pessoa *elemento[MAX];
};
void inicializa_fila(Fila *fila)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL)
        exit(1);
    f->inicio = 0;
    f->fim = 0;
}
bool fila_vazia(Fila fila) { return (fila.inicio > fila.fim); }