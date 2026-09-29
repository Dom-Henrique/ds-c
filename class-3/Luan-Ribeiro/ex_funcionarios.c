#include <stdio.h>
#include <string.h>

#define MAX 15

typedef struct {
    int matricula;
    char nome[100];
    int idade;
    float salario;
} Funcionario;

// adiciona no final do vetor
void adicionar(Funcionario v[], int *tam) {
    if (*tam >= MAX) {
        printf("Vetor cheio!\n");
        return;
    }

    printf("Matricula: ");
    scanf("%d", &v[*tam].matricula);
    printf("Nome: ");
    scanf(" %[^\n]", v[*tam].nome);
    printf("Idade: ");
    scanf("%d", &v[*tam].idade);
    printf("Salario: ");
    scanf("%f", &v[*tam].salario);

    *tam = *tam + 1;
    printf("Funcionario adicionado!\n");
}

// procura pela matricula, retorna a posicao ou -1
int buscar(Funcionario v[], int tam, int matricula) {
    int i;
    for (i = 0; i < tam; i++) {
        if (v[i].matricula == matricula) {
            return i;
        }
    }
    return -1;
}

// remove e puxa os outros pra tras
void remover(Funcionario v[], int *tam) {
    int matricula, i, pos;

    printf("Matricula para remover: ");
    scanf("%d", &matricula);

    pos = buscar(v, *tam, matricula);

    if (pos == -1) {
        printf("Nao encontrado!\n");
        return;
    }

    for (i = pos; i < *tam - 1; i++) {
        v[i] = v[i + 1];
    }
    *tam = *tam - 1;
    printf("Removido!\n");
}

void imprimir(Funcionario v[], int tam) {
    int i;

    if (tam == 0) {
        printf("Nenhum funcionario cadastrado.\n");
        return;
    }

    for (i = 0; i < tam; i++) {
        printf("Matricula: %d\n", v[i].matricula);
        printf("Nome: %s\n", v[i].nome);
        printf("Idade: %d\n", v[i].idade);
        printf("Salario: %.2f\n", v[i].salario);
        printf("-----------------\n");
    }
}

void salvar(Funcionario v[], int tam) {
    FILE *arq;
    int i;

    arq = fopen("funcionarios.csv", "w");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arq, "matricula;nome;idade;salario\n");
    for (i = 0; i < tam; i++) {
        fprintf(arq, "%d;%s;%d;%.2f\n", v[i].matricula, v[i].nome,
                v[i].idade, v[i].salario);
    }

    fclose(arq);
    printf("Salvo com sucesso!\n");
}

void carregar(Funcionario v[], int *tam) {
    FILE *arq;
    char cabecalho[100];
    int i = 0;

    arq = fopen("funcionarios.csv", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fgets(cabecalho, 100, arq); // pula a primeira linha

    while (i < MAX && fscanf(arq, "%d;%[^;];%d;%f\n", &v[i].matricula,
                             v[i].nome, &v[i].idade, &v[i].salario) == 4) {
        i++;
    }

    *tam = i;
    fclose(arq);
    printf("%d funcionario(s) carregado(s)!\n", i);
}

int main() {
    Funcionario funcionarios[MAX];
    int tamanho = 0;
    int opcao, matricula, pos;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar\n");
        printf("2 - Remover\n");
        printf("3 - Imprimir\n");
        printf("4 - Buscar\n");
        printf("5 - Salvar CSV\n");
        printf("6 - Carregar CSV\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            adicionar(funcionarios, &tamanho);
        } else if (opcao == 2) {
            remover(funcionarios, &tamanho);
        } else if (opcao == 3) {
            imprimir(funcionarios, tamanho);
        } else if (opcao == 4) {
            printf("Matricula para buscar: ");
            scanf("%d", &matricula);
            pos = buscar(funcionarios, tamanho, matricula);
            if (pos == -1) {
                printf("Nao encontrado!\n");
            } else {
                printf("Nome: %s\n", funcionarios[pos].nome);
                printf("Idade: %d\n", funcionarios[pos].idade);
                printf("Salario: %.2f\n", funcionarios[pos].salario);
            }
        } else if (opcao == 5) {
            salvar(funcionarios, tamanho);
        } else if (opcao == 6) {
            carregar(funcionarios, &tamanho);
        } else if (opcao == 0) {
            printf("Saindo...\n");
        } else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
