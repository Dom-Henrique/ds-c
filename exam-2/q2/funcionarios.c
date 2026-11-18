#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"

struct funcionario
{
    char nomeCompleto[100];
    int matricula;
    int idade;
    char ocupacao[50];
};

Funcionario *criar_funcionario(const char *nome, int matricula, int idade, const char *ocupacao)
{
    Funcionario *f = (Funcionario *)malloc(sizeof(Funcionario));
    if (f == NULL)
        return NULL;
    strncpy(f->nomeCompleto, nome, sizeof(f->nomeCompleto) - 1);
    f->nomeCompleto[sizeof(f->nomeCompleto) - 1] = '\0';
    f->matricula = matricula;
    f->idade = idade;
    strncpy(f->ocupacao, ocupacao, sizeof(f->ocupacao) - 1);
    f->ocupacao[sizeof(f->ocupacao) - 1] = '\0';
    return f;
}

void alterar_dados(Funcionario *f, const char *nome, int matricula, int idade, const char *ocupacao)
{
    if (f == NULL)
        return;
    strncpy(f->nomeCompleto, nome, sizeof(f->nomeCompleto) - 1);
    f->nomeCompleto[sizeof(f->nomeCompleto) - 1] = '\0';
    f->matricula = matricula;
    f->idade = idade;
    strncpy(f->ocupacao, ocupacao, sizeof(f->ocupacao) - 1);
    f->ocupacao[sizeof(f->ocupacao) - 1] = '\0';
}

int pegar_matricula(const Funcionario *f)
{
    return f ? f->matricula : -1;
}

int pegar_idade(const Funcionario *f)
{
    return f ? f->idade : -1;
}

const char *pegar_nome(const Funcionario *f)
{
    return f ? f->nomeCompleto : NULL;
}

const char *pegar_ocupacao(const Funcionario *f)
{
    return f ? f->ocupacao : NULL;
}

void imprimir_func(const Funcionario *f)
{
    if (f == NULL)
        return;
    printf("Matricula: %d | Nome: %s | Idade: %d | Ocupacao: %s\n",
           f->matricula, f->nomeCompleto, f->idade, f->ocupacao);
}

void liberar_func(Funcionario *f)
{
    free(f);
}