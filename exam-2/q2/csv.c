#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionarios.h"
#include "lista.h"

int salvar_csv(const ListaFunc *lf, const char *arquivo)
{
    FILE *fp = fopen(arquivo, "w");
    if (!fp)
        return 0;
 
    int total = tamanho_lista(lf);
    for (int i = 0; i < total; i++)
    {
        Funcionario *f = obter_func(lf, i);
        fprintf(fp, "%s;%d;%d;%s\n",
                pegar_nome(f), pegar_matricula(f),
                pegar_idade(f), pegar_ocupacao(f));
    }
    fclose(fp);
    return 1;
}
 
int carregar_csv(ListaFunc *lf, const char *arquivo)
{
    FILE *fp = fopen(arquivo, "r");
    if (!fp)
        return -1;
 
    char linha[256], nome[100], ocupacao[50];
    int matricula, idade, lidos = 0;
 
    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%99[^;];%d;%d;%49[^\r\n]",
                   nome, &matricula, &idade, ocupacao) != 4)
            continue;
        if (buscar_func(matricula, lf))
            continue; // aq se a matricula for repetida vai passar direto
 
        Funcionario *f = criar_funcionario(nome, matricula, idade, ocupacao);
        if (!f)
            continue;
 
        int antes = tamanho_lista(lf);
        adicionar_func(lf, f);
        if (tamanho_lista(lf) == antes)
        {
            liberar_func(f);
            break;
        }
        lidos++;
    }
    fclose(fp);
    return lidos;
}