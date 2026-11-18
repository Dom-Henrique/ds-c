#ifndef CSV_H
#define CSV_H

#include "lista.h"

int salvar_csv(const ListaFunc *lf, const char *arquivo);
int carregar_csv(ListaFunc *lf, const char *arquivo);

#endif