#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#define MAX 50 // aqui devo definir um limite pois usamos um vetor

/*
aqui eu tenho que criar um vetor que armazena os valores
o int valor vai servir pra guardar o endereço
*/
struct pilha
{
    int elementos;
    float vetor[MAX];
};
Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    if (p == NULL)
        exit(1);
    p->elementos = 0;
    return p;
}
void pilha_push(Pilha *p, float n)
{
    if (p->elementos == MAX)
    {
        printf("Capacidade excedida!\n");
        exit(1);
    }
    p->vetor[p->elementos] = n; // aqui ele recebe o valor
    p->elementos++;
}
/*
a logica no pop consiste em criar um valor
que armazena o dado como um backup
*/
float pilha_pop(Pilha *p)
{
    float v;
    if (pilha_vazia(p))
    {
        printf("Pilha vazia\n");
        exit(1);
    }
    v = p->vetor[p->elementos-1];
    p->elementos--; // decresce os indices
    return v;
}
void pilha_libera(Pilha *p)
{
    if (p != NULL)
        free(p);
}
int pilha_vazia(Pilha *p)
{
    return (p->elementos == 0); // se nao houver elementos
}