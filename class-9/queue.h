#ifndef QUEUE_H
#define QUEUE_H

typedef struct pessoa Pessoa;
typedef struct fila Fila; // vai possuir posicoes do primeiro e segundo
void inicializa_fila(Fila* fila);
bool fila_vazia(Fila fila);
/*
aqui ele vai manipular os indices de inicio e fim
*/
void enfileirar(Fila* fila, Pessoa* p);
void desenfileirar(Fila* fila);


#endif