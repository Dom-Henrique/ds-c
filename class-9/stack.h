#ifndef STACK_H
#define STACK_H

typedef struct pilha Pilha;

Pilha* pilha_cria(void);
void pilha_push(Pilha* p, float v); // preciso de um elementos
float pilha_pop(Pilha* p); // aqui ele nao precisa
int pilha_vazia(Pilha* p);
void pilha_libera(Pilha* p);

#endif