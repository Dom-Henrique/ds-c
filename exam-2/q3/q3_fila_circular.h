#ifndef Q3_FILA_CIRCULAR_H
#define Q3_FILA_CIRCULAR_H

#define MAX_FILA 10
#define TAM_NOME 50

/* Prioridades: menor numero = maior prioridade */
#define PRIO_DIRETOR      1
#define PRIO_COORDENADOR  2
#define PRIO_FUNCIONARIO  3

typedef struct {
    int  id;                 // numero do documento
    char solicitante[TAM_NOME];
    char arquivo[TAM_NOME];
    int  prioridade;
} Documento;
typedef struct {
    Documento itens[MAX_FILA];
    int inicio;
    int tamanho; 
} Fila;
void inicializar(Fila *f);
int  filaVazia(const Fila *f);
int  filaCheia(const Fila *f);
int  tamanhoFila(const Fila *f);
int  enfileirar(Fila *f, Documento d);
int  desenfileirar(Fila *f, Documento *d);
void imprimirFila(const Fila *f);
const char *nomePrioridade(int prioridade);

#endif
