#ifndef LISTA_H
#define LISTA_H

#include "funcionarios.h"

typedef struct listaFunc ListaFunc;

ListaFunc *criar_lista(void);
void adicionar_func(ListaFunc *lf, Funcionario *f);
int remover_nome(ListaFunc *lf, const char *nome);
int remover_matricula(ListaFunc *lf, int matricula);
Funcionario *buscar_func(int matricula, ListaFunc *lf);
void imprimir_dados(const ListaFunc *lf);
void liberar_lista(ListaFunc *lf);
int tamanho_lista(const ListaFunc *lf);
Funcionario *obter_func(const ListaFunc *lf, int pos);

#endif