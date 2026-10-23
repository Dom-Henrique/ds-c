#include <stdio.h>
#include <math.h>
#include "matriz.h"

int colunas, linhas, tam;
void dimensionarMatriz(int i, int j)
{
    linhas = i;
    colunas = j;
    tam = i * j;
}
void zerarMatriz(int vet[])
{
    for (int i = 0; i < tam; i++)
    {
        vet[i] = 0;
    }
}
int indice(int i, int j)
{
    return (i - 1) * colunas + (j - 1);
}
void imprimirMatriz(int vet[], int l, int c)
{
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            printf("%d ", vet[indice(i, j)]);
        }
        printf("\n");
    }
}
void adicionarElemento(int vet[], int valor, int i, int j)
{
    int ind = indice(i, j);
    vet[ind] = valor;
}
int buscaElemento(int vet[], int i, int j)
{
    int element = indice(i, j);
    return vet[element];
}