#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define SZ 50

struct listaFunc
{
    Funcionario *vetor[SZ];
    int n;
};

ListaFunc *criar_lista(void)
{
    ListaFunc *lf = (ListaFunc *)malloc(sizeof(ListaFunc));
    if (lf == NULL)
        return NULL;
    lf->n = 0;
    return lf;
}

void adicionar_func(ListaFunc *lf, Funcionario *f)
{
    if (lf == NULL || f == NULL)
        return;
    if (lf->n >= SZ)
    {
        printf("Lista cheia!\n");
        return;
    }
    lf->vetor[lf->n++] = f;
}

static void remover_posicao(ListaFunc *lf, int i)
{
    for (int j = i; j < lf->n - 1; j++)
        lf->vetor[j] = lf->vetor[j + 1];
    lf->n--;
}

int remover_nome(ListaFunc *lf, const char *nome)
{
    if (lf == NULL)
        return 0;
    for (int i = 0; i < lf->n; i++)
    {
        if (strcmp(pegar_nome(lf->vetor[i]), nome) == 0)
        {
            remover_posicao(lf, i);
            return 1;
        }
    }
    return 0;
}

int remover_matricula(ListaFunc *lf, int matricula)
{
    if (lf == NULL)
        return 0;
    for (int i = 0; i < lf->n; i++)
    {
        if (pegar_matricula(lf->vetor[i]) == matricula)
        {
            remover_posicao(lf, i);
            return 1;
        }
    }
    return 0;
}

Funcionario *buscar_func(int matricula, ListaFunc *lf)
{
    if (lf == NULL)
        return NULL;
    for (int i = 0; i < lf->n; i++)
        if (pegar_matricula(lf->vetor[i]) == matricula)
            return lf->vetor[i];
    return NULL;
}

void imprimir_dados(const ListaFunc *lf)
{
    if (lf == NULL)
        return;
    for (int i = 0; i < lf->n; i++)
        imprimir_func(lf->vetor[i]);
}

void liberar_lista(ListaFunc *lf)
{
    free(lf);
}

int tamanho_lista(const ListaFunc *lf)
{
    return lf ? lf->n : 0;
}

Funcionario *obter_func(const ListaFunc *lf, int pos)
{
    if (!lf || pos < 0 || pos >= lf->n)
        return NULL;
    return lf->vetor[pos];
}