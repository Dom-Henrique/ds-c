#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no No;

struct no
{
    int valor;
    No *proximo;
};

struct fila
{
    No *inicio;
    No *fim;
    int n;
};

Fila *criar_fila(void)
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    if (f == NULL)
        return NULL;
    f->inicio = f->fim = NULL;
    f->n = 0;
    return f;
}

int enfileirar(Fila *f, int valor)
{
    if (f == NULL)
        return 0;
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;
    novo->valor = valor;
    novo->proximo = NULL;

    if (f->fim)
        f->fim->proximo = novo;
    else
        f->inicio = novo;
    f->fim = novo;
    f->n++;
    return 1;
}

int desenfileirar(Fila *f, int *valor)
{
    if (f == NULL || f->inicio == NULL)
        return 0;
    No *rem = f->inicio;
    if (valor)
        *valor = rem->valor;
    f->inicio = rem->proximo;
    if (f->inicio == NULL)
        f->fim = NULL;
    free(rem);
    f->n--;
    return 1;
}

int frente(const Fila *f, int *valor)
{
    if (f == NULL || f->inicio == NULL)
        return 0;
    if (valor)
        *valor = f->inicio->valor;
    return 1;
}

int fila_vazia(const Fila *f)
{
    return f == NULL || f->inicio == NULL;
}

int fila_cheia(const Fila *f)
{
    (void)f;
    return 0;
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
    for (No *p = f->inicio; p; p = p->proximo)
        printf(" %d", p->valor);
    printf("\n");
}

void liberar_fila(Fila *f)
{
    if (f == NULL)
        return;
    No *cur = f->inicio;
    while (cur)
    {
        No *prox = cur->proximo;
        free(cur);
        cur = prox;
    }
    free(f);
}