#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Funcionario
{
    char nome[60], endereco[60], cpf[60], estadoCivil[60];
    char nascimento[60], escolaridade[60], cargo[60];
    float salario;
    char admissao[60];
};

struct No
{
    struct Funcionario dados;
    struct No *proximo;
};

struct No *inicio = NULL;
int total = 0;
int comparacoes = 0, movimentacoes = 0;

void mostraContadores()
{
    printf(">> Comparacoes: %d | Movimentacoes: %d\n", comparacoes, movimentacoes);
}

void lerCampo(char msg[], char texto[])
{
    printf("%s", msg);
    if (scanf(" %59[^\n]", texto) != 1) exit(0);
}

int lerNumero(char msg[])
{
    char texto[60];
    int n = -1;
    lerCampo(msg, texto);
    sscanf(texto, "%d", &n);
    return n;
}

void preencheFicha(struct No *no)
{
    char texto[60];

    lerCampo("Nome: ", no->dados.nome);
    lerCampo("Endereco: ", no->dados.endereco);
    lerCampo("CPF: ", no->dados.cpf);
    lerCampo("Estado civil: ", no->dados.estadoCivil);
    lerCampo("Data de nascimento (dd/mm/aaaa): ", no->dados.nascimento);
    lerCampo("Escolaridade: ", no->dados.escolaridade);
    lerCampo("Cargo: ", no->dados.cargo);
    lerCampo("Salario: ", texto);
    for (int i = 0; texto[i] != '\0'; i++)
        if (texto[i] == ',') texto[i] = '.';
    no->dados.salario = atof(texto);
    lerCampo("Data de admissao (dd/mm/aaaa): ", no->dados.admissao);
}

void mostraFicha(struct No *no, int pos)
{
    printf("Posicao %d\n", pos);
    printf("Nome: %s\nEndereco: %s\nCPF: %s\n", no->dados.nome, no->dados.endereco, no->dados.cpf);
    printf("Estado civil: %s\nNascimento: %s\n", no->dados.estadoCivil, no->dados.nascimento);
    printf("Escolaridade: %s\nCargo: %s\n", no->dados.escolaridade, no->dados.cargo);
    printf("Salario: R$ %.2f\nAdmissao: %s\n--------------------------\n", no->dados.salario, no->dados.admissao);
}

void inserir(int pos)
{
    if (pos < 0 || pos > total)
    {
        printf("Posicao invalida!\n");
        return;
    }

    struct No *novo = malloc(sizeof(struct No));
    if (novo == NULL)
    {
        printf("Sem memoria!\n");
        return;
    }
    preencheFicha(novo);

    comparacoes = 0;
    movimentacoes = 0;
    if (pos == 0)
    {
        novo->proximo = inicio;
        inicio = novo;
    }
    else
    {
        struct No *anterior = inicio;
        for (int i = 1; i < pos; i++)
            anterior = anterior->proximo;
        novo->proximo = anterior->proximo;
        anterior->proximo = novo;
    }
    total++;
    printf("Inserido na posicao %d!\n", pos + 1);
    mostraContadores();
}

void remover()
{
    char cpf[60];
    lerCampo("CPF a remover: ", cpf);
    comparacoes = 0;
    movimentacoes = 0;

    struct No *anterior = NULL;
    struct No *atual = inicio;
    while (atual != NULL)
    {
        comparacoes++;
        if (strcmp(atual->dados.cpf, cpf) == 0) break;
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
        printf("Nao encontrado!\n");
    else
    {
        if (anterior == NULL) inicio = atual->proximo;
        else anterior->proximo = atual->proximo;
        free(atual);
        total--;
        printf("Removido!\n");
    }
    mostraContadores();
}

void buscar()
{
    char cpf[60];
    lerCampo("CPF a buscar: ", cpf);
    comparacoes = 0;
    movimentacoes = 0;

    struct No *atual = inicio;
    int pos = 1;
    while (atual != NULL)
    {
        comparacoes++;
        if (strcmp(atual->dados.cpf, cpf) == 0) break;
        atual = atual->proximo;
        pos++;
    }

    if (atual == NULL) printf("Nao encontrado!\n");
    else mostraFicha(atual, pos);
    mostraContadores();
}

int comparaNomes(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' && tolower(a[i]) == tolower(b[i])) i++;
    return tolower(a[i]) - tolower(b[i]);
}

void ordenar()
{
    struct Funcionario aux;
    struct No *menor;

    comparacoes = 0;
    movimentacoes = 0;
    for (struct No *i = inicio; i != NULL; i = i->proximo)
    {
        menor = i;
        for (struct No *j = i->proximo; j != NULL; j = j->proximo)
        {
            comparacoes++;
            if (comparaNomes(j->dados.nome, menor->dados.nome) < 0) menor = j;
        }
        if (menor != i)
        {
            aux = i->dados;
            i->dados = menor->dados;
            menor->dados = aux;
            movimentacoes += 3;
        }
    }
    printf("Lista ordenada por nome!\n");
    mostraContadores();
}

void listar()
{
    int pos = 1;
    if (inicio == NULL) printf("Ninguem cadastrado.\n");
    for (struct No *atual = inicio; atual != NULL; atual = atual->proximo)
        mostraFicha(atual, pos++);
}

void liberarLista()
{
    struct No *proximo;
    while (inicio != NULL)
    {
        proximo = inicio->proximo;
        free(inicio);
        inicio = proximo;
    }
}

int main()
{
    int opcao;

    do
    {
        printf("\n===== FUNCIONARIOS (%d) =====\n", total);
        printf("1 - Cadastrar (no final)\n2 - Inserir em uma posicao\n3 - Remover por CPF\n");
        printf("4 - Buscar por CPF\n5 - Ordenar por nome\n6 - Listar\n0 - Sair\n");
        opcao = lerNumero("Opcao: ");

        if (opcao == 1) inserir(total);
        else if (opcao == 2) inserir(lerNumero("Posicao (1 a total+1): ") - 1);
        else if (opcao == 3) remover();
        else if (opcao == 4) buscar();
        else if (opcao == 5) ordenar();
        else if (opcao == 6) listar();
        else if (opcao != 0) printf("Opcao invalida!\n");
    } while (opcao != 0);

    liberarLista();
    return 0;
}
