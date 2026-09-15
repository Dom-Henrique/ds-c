#include <stdio.h>
#include <math.h>

int linhas, colunas, tam;

void dimensionaMatriz(int l, int c) {
    linhas = l;
    colunas = c;
    tam = l * c;
}

void zeraMatriz(int vet[]) {
    for (int i = 0; i < tam; i++) vet[i] = 0;
}

int indice(int i, int j) {
    return (i - 1) * colunas + (j - 1);
}

void adicionaElemento(int vet[], int valor, int i, int j) {
    vet[indice(i, j)] = valor;
}

int buscaElemento(int vet[], int i, int j) {
    return vet[indice(i, j)];
}

void imprimeMatriz(int vet[], int l, int c) {
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= c; j++)
            printf("%4d", vet[indice(i, j)]);
        printf("\n");
    }
    printf("\n");
}

void somaMatriz() {
    int a[9] = {1,2,3,4,5,6,7,8,9};
    int b[9] = {9,8,7,6,5,4,3,2,1};
    for (int i = 0; i < 9; i++) {
        printf("%4d", a[i] + b[i]);
        if ((i + 1) % 3 == 0) printf("\n");
    }
}

int main() {
    dimensionaMatriz(3, 3);
    int vet[tam];

    zeraMatriz(vet);
    imprimeMatriz(vet, linhas, colunas);

    adicionaElemento(vet, 15, 1, 1);
    adicionaElemento(vet, 25, 2, 2);
    adicionaElemento(vet, 35, 3, 3);
    imprimeMatriz(vet, linhas, colunas);

    printf("O elemento que esta na linha 2 coluna 2 eh: %d\n\n", buscaElemento(vet, 2, 2));

    printf("Soma Matrizes:\n");
    somaMatriz();

    return 0;
}