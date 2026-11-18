#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H

typedef struct funcionario Funcionario;

Funcionario *criar_funcionario(const char *nome, int matricula, int idade, const char *ocupacao);
void alterar_dados(Funcionario *f, const char *nome, int matricula, int idade, const char *ocupacao);
int pegar_matricula(const Funcionario *f);
int pegar_idade(const Funcionario *f);
const char *pegar_nome(const Funcionario *f);
const char *pegar_ocupacao(const Funcionario *f);
void imprimir_func(const Funcionario *f);
void liberar_func(Funcionario *f);

#endif