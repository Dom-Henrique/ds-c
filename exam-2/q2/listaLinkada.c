#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "funcionarios.h"

typedef struct node Node;

struct node
{
    Funcionario *func;
    Node *proximo;
};

struct listaFunc
{
    Node *cabeca;
    Node *cauda;
    int n;
};

ListaFunc *criar_lista(void)
{
    ListaFunc *lk = (ListaFunc *)malloc(sizeof(ListaFunc));
    if (lk == NULL)
        return NULL;
    lk->cabeca = lk->cauda = NULL;
    lk->n = 0;
    return lk;
}

void adicionar_func(ListaFunc *lk, Funcionario *f)
{
    if (!lk || !f)
        return;

    Node *n = (Node *)malloc(sizeof(Node));
    if (!n)
        return;
    n->func = f;
    n->proximo = NULL;

    Node *prev = NULL, *cur = lk->cabeca;
    while (cur && strcmp(pegar_nome(cur->func), pegar_nome(f)) <= 0)
    {
        prev = cur;
        cur = cur->proximo;
    }

    if (prev == NULL)
    {
        n->proximo = lk->cabeca;
        lk->cabeca = n;
    }
    else
    {
        prev->proximo = n;
        n->proximo = cur;
    }

    if (cur == NULL)
        lk->cauda = n;

    lk->n++;
}

static void remover_no(ListaFunc *lk, Node *prev, Node *cur)
{
    if (prev)
        prev->proximo = cur->proximo;
    else
        lk->cabeca = cur->proximo;

    if (cur == lk->cauda)
        lk->cauda = prev;

    free(cur);
    lk->n--;
}

int remover_nome(ListaFunc *lk, const char *nome)
{
    if (!lk || !nome)
        return 0;

    Node *prev = NULL, *cur = lk->cabeca;
    while (cur && strcmp(pegar_nome(cur->func), nome) != 0)
    {
        prev = cur;
        cur = cur->proximo;
    }
    if (!cur)
        return 0;

    remover_no(lk, prev, cur);
    return 1;
}

int remover_matricula(ListaFunc *lk, int matricula)
{
    if (!lk)
        return 0;

    Node *prev = NULL, *cur = lk->cabeca;
    while (cur && pegar_matricula(cur->func) != matricula)
    {
        prev = cur;
        cur = cur->proximo;
    }
    if (!cur)
        return 0;

    remover_no(lk, prev, cur);
    return 1;
}

Funcionario *buscar_func(int matricula, ListaFunc *lk)
{
    if (!lk)
        return NULL;

    Node *p;
    for (p = lk->cabeca; p; p = p->proximo)
        if (pegar_matricula(p->func) == matricula)
            return p->func;
    return NULL;
}

void imprimir_dados(const ListaFunc *lk)
{
    if (!lk)
        return;
    Node *p;
    for (p = lk->cabeca; p; p = p->proximo)
        imprimir_func(p->func);
}

void liberar_lista(ListaFunc *lk)
{
    if (!lk)
        return;

    Node *cur = lk->cabeca;
    while (cur)
    {
        Node *next = cur->proximo;
        free(cur);
        cur = next;
    }
    free(lk);
}

int tamanho_lista(const ListaFunc *lk)
{
    return lk ? lk->n : 0;
}

Funcionario *obter_func(const ListaFunc *lk, int pos)
{
    if (!lk || pos < 0 || pos >= lk->n)
        return NULL;
    Node *p = lk->cabeca;
    while (pos-- > 0)
        p = p->proximo;
    return p->func;
}