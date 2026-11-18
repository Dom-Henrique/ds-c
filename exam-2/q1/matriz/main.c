#include <stdio.h>
#include <matriz.h>

int main()
{
    int colunas, linhas, tam;
    dimensionarMatriz(3, 3);
    int vet[tam];

    zerarMatriz(vet);

    imprimirMatriz(vet, linhas, colunas);
    printf("\n");
    adicionarElemento(vet, 15, 1, 1);
    adicionarElemento(vet, 25, 2, 2);
    adicionarElemento(vet, 35, 3, 3);

    imprimirMatriz(vet, linhas, colunas);
    printf("\n");
    printf("O elemento que ta na linha 2 e coluna 2 eh %d\n", buscaElemento(vet, 2, 2));
}