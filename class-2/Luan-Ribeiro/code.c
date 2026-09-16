#include <stdio.h>

int linhas = 0;
int colunas = 0;
int tam = 0;

void dimensionaMatriz(int l, int c) {
    linhas = l;
    colunas = c;
    tam = l * c;
}

void zeraMatriz(int vet[]) {
    for (int k = 0; k < tam; k++) {
        vet[k] = 0;
    }
}

void adicionaElemento(int vet[], int valor, int i, int j) {
    int k = (i - 1) * colunas + (j - 1);
    if (k >= 0 && k < tam) {
        vet[k] = valor;
    }
}

int buscaElemento(int vet[], int i, int j) {
    int k = (i - 1) * colunas + (j - 1);
    if (k >= 0 && k < tam) {
        return vet[k];
    }
    return 0;
}

void imprimeMatriz(int vet[], int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            int k = i * c + j;
            printf("%d\t", vet[k]);
        }
        printf("\n");
    }
    printf("\n");
}

int somaMatriz(int vet[]) {
    int soma = 0;
    for (int k = 0; k < tam; k++) {
        soma += vet[k];
    }
    return soma;
}

int main() {
    dimensionaMatriz(3, 3);
    int vet[9];

    zeraMatriz(vet);
    imprimeMatriz(vet, linhas, colunas);

    adicionaElemento(vet, 15, 1, 1);
    adicionaElemento(vet, 25, 2, 2);
    adicionaElemento(vet, 35, 3, 3);

    imprimeMatriz(vet, linhas, colunas);

    printf("O elemento que esta na linha 2 coluna 2 eh: %d\n\n", buscaElemento(vet, 2, 2));
    printf("Soma Matrizes: %d\n", somaMatriz(vet));

    return 0;
}
