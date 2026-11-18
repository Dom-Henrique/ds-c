#include <stdio.h>
#include "fila.h"
#define LIMPAR_ENTRADA while ((c = getchar()) != '\n' && c != EOF)

int main(void)
{
    int c;
    Fila *f = criar_fila();
    if (!f)
    {
        printf("Erro ao criar a fila.\n");
        return 1;
    }

    int opcao;
    do
    {
        printf("\n===== FILA =====\n"
               "1 - Enfileirar\n"
               "2 - Desenfileirar\n"
               "3 - Ver o primeiro da fila\n"
               "4 - Imprimir fila\n"
               "5 - Tamanho da fila\n"
               "6 - Esvaziar fila\n"
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
            int valor;
            printf("Valor: ");
            if (scanf("%d", &valor) != 1)
            {
                LIMPAR_ENTRADA;
                printf("Valor invalido.\n");
                break;
            }
            if (enfileirar(f, valor))
                printf("%d enfileirado.\n", valor);
            else if (fila_cheia(f))
                printf("Fila cheia!\n");
            else
                printf("Erro ao enfileirar.\n");
            break;
        }

        case 2:
        {
            int valor;
            if (desenfileirar(f, &valor))
                printf("Saiu da fila: %d\n", valor);
            else
                printf("Fila vazia!\n");
            break;
        }

        case 3:
        {
            int valor;
            if (frente(f, &valor))
                printf("Primeiro da fila: %d\n", valor);
            else
                printf("Fila vazia!\n");
            break;
        }

        case 4:
            if (fila_vazia(f))
                printf("Fila vazia!\n");
            else
                imprimir_fila(f);
            break;

        case 5:
            printf("Tamanho: %d\n", tamanho_fila(f));
            break;

        case 6:
            while (desenfileirar(f, NULL))
                ;
            printf("Fila esvaziada.\n");
            break;

        case 0:
            printf("Ate logo!\n");
            break;

        default:
            printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    liberar_fila(f);
    return 0;
}