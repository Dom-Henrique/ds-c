#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int matrixDimension(int n, int m)
{
    return n * m;
}
int eraseMatrix(int vet[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        vet[i] = 0;
    }
    return vet;
}
void printMatrix(int vet[], int l, int c)
{
    // C = tamanho do vetor
    // L =
    // int k = (l*(int)sizeof(vet))+c;
    for (int i = 0; i < c; i++)
    {
        printf("%d", vet[(i * c) + l]);
    }
}
void addElement(int valor, int vet[], int i, int j, int size)
{
    int k = (i * size) + j;
    vet[k] = valor;
} // vetor, valor, linha, coluna
int searchElement(int vet[], int i, int j, int size)
{
    int k = (i * size) + j;
    return vet[k];
}
int sumMatrix(int vet[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += vet[i];
    }
    return sum;
}

int main()
{
    int tam = matrixDimension(3, 3);
    int vet[tam];
    eraseMatrix(vet, tam);
    printMatrix(vet, 1, tam);
    addElement(vet, 15, 1, 1, tam);
    addElement(vet, 25, 2, 2, tam);
    addElement(vet, 35, 3, 3, tam);
    printMatrix(vet, 1, tam);
    printf("The element there are in row 2 column 2 is: %d\n\n", searchElement(vet, 2, 2, tam));
    printf("Matrixes Sum: %d\n", sumMatrix(vet, tam));
}