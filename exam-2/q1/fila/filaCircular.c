#include <stdio.h>
#include <stdlib.h>
#include "filaCircular.h"
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
    int fim = (f->inicio + f->n) % CAP;
    f->dados[fim] = valor;
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

int capacidade_fila(const Fila *f)
{
    (void)f;
    return CAP;
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

void imprimir_estrutura(const Fila *f)
{
    if (f == NULL)
        return;
    printf("Vetor interno:");
    for (int i = 0; i < CAP; i++)
    {
        int ocupada = ((i - f->inicio + CAP) % CAP) < f->n;
        if (ocupada)
            printf(" [%d]=%d", i, f->dados[i]);
        else
            printf(" [%d]=_", i);
    }
    printf("\ninicio=%d | proxima posicao livre=%d | elementos=%d/%d\n",
           f->inicio, (f->inicio + f->n) % CAP, f->n, CAP);
}

void liberar_fila(Fila *f)
{
    free(f);
}