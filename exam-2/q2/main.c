#include <stdio.h>
#include <string.h>
#include "funcionarios.h"
#include "lista.h"
#include "csv.h"

#define ARQUIVO "funcionarios.csv"
#define LIMPAR_ENTRADA while ((c = getchar()) != '\n' && c != EOF)

int main(void)
{
    int c;
    ListaFunc *lf = criar_lista();
    if (!lf)
    {
        printf("Erro ao criar a lista.\n");
        return 1;
    }

    int lidos = carregar_csv(lf, ARQUIVO);
    if (lidos >= 0)
        printf("%d funcionario(s) carregado(s) de %s.\n", lidos, ARQUIVO);

    int opcao;
    do
    {
        printf("\n===== RENE EMPREENDIMENTOS =====\n"
               "1 - Cadastrar funcionario\n"
               "2 - Remover por matricula\n"
               "3 - Remover por nome\n"
               "4 - Buscar por matricula\n"
               "5 - Listar funcionarios\n"
               "6 - Salvar em CSV\n"
               "0 - Sair\n"
               "Opcao: ");
        if (scanf("%d", &opcao) != 1)
        {
            if (feof(stdin))
                opcao = 0; /* fim da entrada: sai normalmente */
            else
            {
                LIMPAR_ENTRADA;
                opcao = -1;
            }
        }

        switch (opcao)
        {
        case 1:
        {
            char nome[100], ocupacao[50];
            int matricula, idade;

            printf("Nome: ");
            scanf(" %99[^\n]", nome);
            if (strchr(nome, ';'))
            {
                printf("O nome nao pode conter ';'.\n");
                break;
            }
            printf("Matricula: ");
            if (scanf("%d", &matricula) != 1)
            {
                LIMPAR_ENTRADA;
                printf("Matricula invalida.\n");
                break;
            }
            printf("Idade: ");
            if (scanf("%d", &idade) != 1)
            {
                LIMPAR_ENTRADA;
                printf("Idade invalida.\n");
                break;
            }
            printf("Ocupacao: ");
            scanf(" %49[^\n]", ocupacao);
            if (strchr(ocupacao, ';'))
            {
                printf("A ocupacao nao pode conter ';'.\n");
                break;
            }

            if (buscar_func(matricula, lf))
            {
                printf("Ja existe funcionario com essa matricula.\n");
                break;
            }

            Funcionario *f = criar_funcionario(nome, matricula, idade, ocupacao);
            if (!f)
            {
                printf("Erro de memoria.\n");
                break;
            }
            int antes = tamanho_lista(lf);
            adicionar_func(lf, f);
            if (tamanho_lista(lf) == antes) /* lista nao aceitou */
            {
                liberar_func(f);
                printf("Nao foi possivel cadastrar.\n");
            }
            else
                printf("Funcionario cadastrado.\n");
            break;
        }

        case 2:
        {
            int matricula;
            printf("Matricula a remover: ");
            if (scanf("%d", &matricula) != 1)
            {
                LIMPAR_ENTRADA;
                printf("Matricula invalida.\n");
                break;
            }

            Funcionario *f = buscar_func(matricula, lf);
            if (f && remover_matricula(lf, matricula))
            {
                liberar_func(f);
                printf("Removido.\n");
            }
            else
                printf("Funcionario nao encontrado.\n");
            break;
        }

        case 3:
        {
            char nome[100];
            printf("Nome a remover: ");
            scanf(" %99[^\n]", nome);

            Funcionario *alvo = NULL;
            for (int i = 0; i < tamanho_lista(lf) && !alvo; i++)
                if (strcmp(pegar_nome(obter_func(lf, i)), nome) == 0)
                    alvo = obter_func(lf, i);

            if (alvo && remover_nome(lf, nome))
            {
                liberar_func(alvo);
                printf("Removido.\n");
            }
            else
                printf("Funcionario nao encontrado.\n");
            break;
        }

        case 4:
        {
            int matricula;
            printf("Matricula: ");
            if (scanf("%d", &matricula) != 1)
            {
                LIMPAR_ENTRADA;
                printf("Matricula invalida.\n");
                break;
            }

            Funcionario *f = buscar_func(matricula, lf);
            if (f)
                imprimir_func(f);
            else
                printf("Funcionario nao encontrado.\n");
            break;
        }

        case 5:
            if (tamanho_lista(lf) == 0)
                printf("Lista vazia.\n");
            else
                imprimir_dados(lf);
            break;

        case 6:
            if (salvar_csv(lf, ARQUIVO))
                printf("Salvo em %s.\n", ARQUIVO);
            else
                printf("Erro ao salvar %s.\n", ARQUIVO);
            break;

        case 0:
            if (salvar_csv(lf, ARQUIVO))
                printf("Dados salvos. Ate logo!\n");
            else
                printf("Erro ao salvar %s.\n", ARQUIVO);
            break;

        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    for (int i = 0; i < tamanho_lista(lf); i++)
        liberar_func(obter_func(lf, i));
    liberar_lista(lf);

    return 0;
}