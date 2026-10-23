#define MATRIZ_H
#ifndef MATRIZ_H

void dimensionarMatriz(int i, int j);
void zerarMatriz(int vet[]);
int indice(int i, int j);
void imprimirMatriz(int vet[], int l, int c);
void adicionarElemento(int vet[], int valor, int i, int j);
int buscaElemento(int vet[], int i, int j);

#endif