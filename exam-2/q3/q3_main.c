#include <stdio.h>
#include <string.h>
#include "q3_fila_circular.h"

static void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static void lerTexto(const char *rotulo, char *dest, int tam) {
    printf("%s", rotulo);
    if (fgets(dest, tam, stdin)) dest[strcspn(dest, "\n")] = '\0';
}

int main() {
    Fila spooler;
    int opcao, proximoId = 1;

    inicializar(&spooler);

    do {
        printf("\n===== SPOOLER DE IMPRESSAO =====\n");
        printf("1 - Enviar documento para impressao\n");
        printf("2 - Imprimir proximo documento\n");
        printf("3 - Mostrar fila de impressao\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) { limparBuffer(); opcao = -1; continue; }
        limparBuffer();

        switch (opcao) {
            case 1: {
                Documento d;
                int cargo;
                if (filaCheia(&spooler)) {
                    printf("Fila cheia! Aguarde a impressao de algum documento.\n");
                    break;
                }
                lerTexto("Nome do solicitante: ", d.solicitante, TAM_NOME);
                lerTexto("Nome do arquivo: ", d.arquivo, TAM_NOME);
                printf("Cargo (1-Diretor, 2-Coordenador, 3-Funcionario): ");
                if (scanf("%d", &cargo) != 1 || cargo < 1 || cargo > 3) {
                    limparBuffer();
                    printf("Cargo invalido!\n");
                    break;
                }
                limparBuffer();
                d.prioridade = cargo;
                d.id = proximoId++;
                enfileirar(&spooler, d);
                printf("Documento %d enviado para a fila.\n", d.id);
                break;
            }
            case 2: {
                Documento d;
                if (desenfileirar(&spooler, &d))
                    printf("Imprimindo documento %d \"%s\" de %s (%s)...\n",
                           d.id, d.arquivo, d.solicitante, nomePrioridade(d.prioridade));
                else
                    printf("Nao ha documentos na fila.\n");
                break;
            }
            case 3:
                imprimirFila(&spooler);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
