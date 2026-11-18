#ifndef Q3_FILA_CIRCULAR_H
#define Q3_FILA_CIRCULAR_H

typedef struct fila Fila;

Fila *criar_fila(void);
int enfileirar(Fila *f, int valor);
int desenfileirar(Fila *f, int *valor);
int frente(const Fila *f, int *valor);
int fila_vazia(const Fila *f);
int fila_cheia(const Fila *f);
int tamanho_fila(const Fila *f);
int capacidade_fila(const Fila *f);
void imprimir_fila(const Fila *f);
void imprimir_estrutura(const Fila *f);
void liberar_fila(Fila *f);

#endif