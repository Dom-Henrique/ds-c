#include <stdio.h>
#include "stack.h"
#define LIMPAR_ENTRADA while ((c = getchar()) != '\n' && c != EOF)

int main()
{
    int c;
    Pilha *p = pilha_cria();
    if (!p)
    {
        printf("Erro ao criar a pilha.\n");
        return 1;
    }

    int opcao;
    do
    {
        printf("\n===== PILHA =====\n"
               "1 - Empilhar (push)\n"
               "2 - Desempilhar (pop)\n"
               "3 - Ver o topo\n"
               "4 - Imprimir pilha\n"
               "5 - Verificar se esta vazia\n"
               "6 - Esvaziar pilha\n"
               "0 - Sair\n"
               "Opcao: ");
        if (scanf("%d", &opcao) != 1)
        {
            if (feof(stdin))
                opcao = 0;
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
            float valor;
            printf("Valor: ");
            if (scanf("%f", &valor) != 1)
            {
                LIMPAR_ENTRADA;
                printf("Valor invalido.\n");
                break;
            }
            pilha_push(p, valor);
            printf("%g empilhado.\n", valor);
            break;
        }

        case 2:
            if (pilha_vazia(p))
                printf("Pilha vazia!\n");
            else
                printf("Desempilhado: %g\n", pilha_pop(p));
            break;

        case 3:
            if (pilha_vazia(p))
                printf("Pilha vazia!\n");
            else
            {
                float topo = pilha_pop(p);
                pilha_push(p, topo);
                printf("Topo: %g\n", topo);
            }
            break;

        case 4:
            if (pilha_vazia(p))
                printf("Pilha vazia!\n");
            else
            {
                Pilha *aux = pilha_cria();
                printf("Pilha (topo -> base):");
                while (!pilha_vazia(p))
                {
                    float v = pilha_pop(p);
                    printf(" %g", v);
                    pilha_push(aux, v);
                }
                printf("\n");
                while (!pilha_vazia(aux))
                    pilha_push(p, pilha_pop(aux));
                pilha_libera(aux);
            }
            break;

        case 5:
            printf(pilha_vazia(p) ? "A pilha esta vazia.\n"
                                  : "A pilha NAO esta vazia.\n");
            break;

        case 6:
            while (!pilha_vazia(p))
                pilha_pop(p);
            printf("Pilha esvaziada.\n");
            break;

        case 0:
            printf("Ate logo!\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    pilha_libera(p);
}