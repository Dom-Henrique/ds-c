#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct no
{
    float informacao;
    struct no *proximo;
};
typedef struct no No; // aqui ele referencia com o de cima
struct pilha
{
    No *primeiro;
};
/*
sempre se refere ao próximo por ser LIFO
*/
Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->primeiro = NULL;
    /*
    o primeiro elemento deve ser nulo porque se refere
    à cabeça da lista linkada
    */
    return p;
}
No *inserir_inicio(float valor, No *proximo)
{
    No *p = (No *)malloc(sizeof(No));
    p->informacao = valor;
    p->proximo = proximo;
    return p;
}
/*
aqui usamos um backup para armazenar o item e depois liberamos o espaco
*/
No *remover_inicio(No *proximo)
{
    No *p = proximo->proximo;
    free(proximo);
    return p;
}
void pilha_push(Pilha *p, float v)
{
    p->primeiro = inserir_inicio(v, p->primeiro);
}
float pilha_pop(Pilha *p)
{
    // usamos o esquema do backup de novo
    float v;
    if (pilha_vazia(p))
        exit(1);
    v = p->primeiro->informacao;
    // free(p);
    p->primeiro = remover_inicio(p->primeiro);
    return v;
}
void pilha_libera(Pilha *p)
{
    No *q = p->primeiro;
    while (q != NULL)
    {
        No *t = p->primeiro;
        free(q);
        q = t;
    }
    free(p);
}
int pilha_vazia(Pilha *p)
{
    return (p->primeiro == NULL); // se nao houver elementos
}