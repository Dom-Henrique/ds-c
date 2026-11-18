#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "q4_pilha.h"

static int avaliarNPI(const char *expr, double *res, const char **erro) {
    Pilha p;
    char copia[512];
    const char *seps = " ,\t\n";

    inicializarPilha(&p);
    strncpy(copia, expr, sizeof(copia) - 1);
    copia[sizeof(copia) - 1] = '\0';

    for (char *tok = strtok(copia, seps); tok; tok = strtok(NULL, seps)) {
        char *fim;
        double num = strtod(tok, &fim);

        if (*fim == '\0') {
            if (!empilhar(&p, num)) { *erro = "pilha cheia"; return 0; }
        } else if (strlen(tok) == 1 && strchr("+-*/^", tok[0])) {
            double b, a, r;
            if (!desempilhar(&p, &b) || !desempilhar(&p, &a)) {
                *erro = "operandos insuficientes"; return 0;
            }
            switch (tok[0]) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;
                case '/':
                    if (b == 0) { *erro = "divisao por zero"; return 0; }
                    r = a / b; break;
                default:  r = pow(a, b); break;
            }
            empilhar(&p, r);
            printf("  %g %c %g = %g\n", a, tok[0], b, r);
        } else {
            *erro = "token invalido"; return 0;
        }
    }

    if (tamanhoPilha(&p) != 1) {
        *erro = pilhaVazia(&p) ? "expressao vazia" : "operandos sobrando (expressao mal formada)";
        return 0;
    }
    desempilhar(&p, res);
    return 1;
}

int main(void) {
    char linha[512];

    printf("=== Calculadora NPI (Notacao Polonesa Inversa) ===\n");
    printf("Operadores: + - * / ^\n");
    printf("Ex.: 1 2 3 * + 4 -   (ou 1, 2, 3, *, +, 4, -)\n");
    printf("Digite 'sair' para encerrar.\n");

    while (1) {
        printf("\nNPI> ");
        if (!fgets(linha, sizeof(linha), stdin)) break;
        linha[strcspn(linha, "\n")] = '\0';
        if (strcmp(linha, "sair") == 0) break;
        if (linha[0] == '\0') continue;

        double resultado;
        const char *erro = "";
        if (avaliarNPI(linha, &resultado, &erro))
            printf("Resposta final: %g\n", resultado);
        else
            printf("Erro: %s\n", erro);
    }
    return 0;
}
