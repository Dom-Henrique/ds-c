#ifndef Q4_PILHA_H
#define Q4_PILHA_H

#define MAX_PILHA 100

typedef struct {
    double itens[MAX_PILHA];
    int topo;
} Pilha;

void inicializarPilha(Pilha *p);
int  pilhaVazia(const Pilha *p);
int  pilhaCheia(const Pilha *p);
int  tamanhoPilha(const Pilha *p);
int  empilhar(Pilha *p, double valor);
int  desempilhar(Pilha *p, double *valor);

#endif
