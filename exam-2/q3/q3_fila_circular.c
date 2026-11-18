#include <stdio.h>
#include "q3_fila_circular.h"

void inicializar(Fila *f) {
    f->inicio = 0;
    f->tamanho = 0;
}

int filaVazia(const Fila *f) { return f->tamanho == 0; }
int filaCheia(const Fila *f) { return f->tamanho == MAX_FILA; }
int tamanhoFila(const Fila *f) { return f->tamanho; }

const char *nomePrioridade(int prioridade) {
    switch (prioridade) {
        case PRIO_DIRETOR:     return "Diretor";
        case PRIO_COORDENADOR: return "Coordenador";
        case PRIO_FUNCIONARIO: return "Funcionario";
        default:               return "Desconhecido";
    }
}

static int pos(const Fila *f, int i) {
    return (f->inicio + i) % MAX_FILA;
}

int enfileirar(Fila *f, Documento d) {
    if (filaCheia(f)) return 0;

    int i = f->tamanho;
    while (i > 0 && f->itens[pos(f, i - 1)].prioridade > d.prioridade) {
        f->itens[pos(f, i)] = f->itens[pos(f, i - 1)];
        i--;
    }
    f->itens[pos(f, i)] = d;
    f->tamanho++;
    return 1;
}

int desenfileirar(Fila *f, Documento *d) {
    if (filaVazia(f)) return 0;
    if (d) *d = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX_FILA;
    f->tamanho--;
    return 1;
}

void imprimirFila(const Fila *f) {
    if (filaVazia(f)) {
        printf("\n[Fila de impressao vazia]\n");
        return;
    }
    printf("\n=== FILA DE IMPRESSAO (%d/%d) ===\n", f->tamanho, MAX_FILA);
    printf("%-4s %-4s %-14s %-12s %s\n", "Pos", "ID", "Solicitante", "Cargo", "Arquivo");
    for (int i = 0; i < f->tamanho; i++) {
        const Documento *d = &f->itens[pos(f, i)];
        printf("%-4d %-4d %-14s %-12s %s\n", i + 1, d->id, d->solicitante,
               nomePrioridade(d->prioridade), d->arquivo);
    }
}
