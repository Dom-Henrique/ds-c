#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define CAP 5

struct fila
{
    int dados[CAP];
    int inicio;
    int n;
};

Fila *criar_fila(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL)
        return NULL;
    f->inicio = 0;
    f->n = 0;
    return f;
}

int enfileirar(Fila *f, int valor)
{
    if (f == NULL || f->n == CAP)
        return 0;
    f->dados[(f->inicio + f->n) % CAP] = valor;
    f->n++;
    return 1;
}

int desenfileirar(Fila *f, int *valor)
{
    if (f == NULL || f->n == 0)
        return 0;
    if (valor)
        *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % CAP;
    f->n--;
    return 1;
}

int frente(const Fila *f, int *valor)
{
    if (f == NULL || f->n == 0)
        return 0;
    if (valor)
        *valor = f->dados[f->inicio];
    return 1;
}

int fila_vazia(const Fila *f)
{
    return f == NULL || f->n == 0;
}

int fila_cheia(const Fila *f)
{
    return f != NULL && f->n == CAP;
}

int tamanho_fila(const Fila *f)
{
    return f ? f->n : 0;
}

void imprimir_fila(const Fila *f)
{
    if (f == NULL)
        return;
    printf("Fila (inicio -> fim):");
    for (int i = 0; i < f->n; i++)
        printf(" %d", f->dados[(f->inicio + i) % CAP]);
    printf("\n");
}

void liberar_fila(Fila *f)
{
    free(f);
}