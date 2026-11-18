#include "q4_pilha.h"

void inicializarPilha(Pilha *p) { p->topo = -1; }
int  pilhaVazia(const Pilha *p) { return p->topo == -1; }
int  pilhaCheia(const Pilha *p) { return p->topo == MAX_PILHA - 1; }
int  tamanhoPilha(const Pilha *p) { return p->topo + 1; }

int empilhar(Pilha *p, double valor) {
    if (pilhaCheia(p)) return 0;
    p->itens[++p->topo] = valor;
    return 1;
}

int desempilhar(Pilha *p, double *valor) {
    if (pilhaVazia(p)) return 0;
    *valor = p->itens[p->topo--];
    return 1;
}
