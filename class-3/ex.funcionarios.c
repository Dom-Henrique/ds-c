#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Funcionario
{
    char nome[60], endereco[60], cpf[60], estadoCivil[60];
    char nascimento[60], escolaridade[60], cargo[60];
    float salario;
    char admissao[60];
};

struct Funcionario lista[MAX];
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

void preencheFicha(int pos)
{
    char texto[60];

    lerCampo("Nome: ", lista[pos].nome);
    lerCampo("Endereco: ", lista[pos].endereco);
    lerCampo("CPF: ", lista[pos].cpf);
    lerCampo("Estado civil: ", lista[pos].estadoCivil);
    lerCampo("Data de nascimento (dd/mm/aaaa): ", lista[pos].nascimento);
    lerCampo("Escolaridade: ", lista[pos].escolaridade);
    lerCampo("Cargo: ", lista[pos].cargo);
    lerCampo("Salario: ", texto);
    for (int i = 0; texto[i] != '\0'; i++)
        if (texto[i] == ',') texto[i] = '.';
    lista[pos].salario = atof(texto);
    lerCampo("Data de admissao (dd/mm/aaaa): ", lista[pos].admissao);
}

void mostraFicha(int pos)
{
    printf("Posicao %d\n", pos + 1);
    printf("Nome: %s\nEndereco: %s\nCPF: %s\n", lista[pos].nome, lista[pos].endereco, lista[pos].cpf);
    printf("Estado civil: %s\nNascimento: %s\n", lista[pos].estadoCivil, lista[pos].nascimento);
    printf("Escolaridade: %s\nCargo: %s\n", lista[pos].escolaridade, lista[pos].cargo);
    printf("Salario: R$ %.2f\nAdmissao: %s\n--------------------------\n", lista[pos].salario, lista[pos].admissao);
}

int buscaCpf(char cpf[])
{
    for (int i = 0; i < total; i++)
    {
        comparacoes++;
        if (strcmp(lista[i].cpf, cpf) == 0) return i;
    }
    return -1;
}

void buscar()
{
    char cpf[60];
    lerCampo("CPF a buscar: ", cpf);
    comparacoes = 0;
    movimentacoes = 0;

    int pos = buscaCpf(cpf);
    if (pos == -1) printf("Nao encontrado!\n");
    else mostraFicha(pos);
    mostraContadores();
}

void inserir(int pos)
{
    if (total == MAX) { printf("Lista cheia!\n"); return; }
    if (pos < 0 || pos > total) { printf("Posicao invalida!\n"); return; }

    comparacoes = 0;
    movimentacoes = 0;
    for (int i = total; i > pos; i--)
    {
        lista[i] = lista[i - 1];
        movimentacoes++;
    }
    preencheFicha(pos);
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

    int pos = buscaCpf(cpf);
    if (pos == -1) printf("Nao encontrado!\n");
    else
    {
        for (int i = pos; i < total - 1; i++)
        {
            lista[i] = lista[i + 1];
            movimentacoes++;
        }
        total--;
        printf("Removido!\n");
    }
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
    int menor;

    comparacoes = 0;
    movimentacoes = 0;
    for (int i = 0; i < total - 1; i++)
    {
        menor = i;
        for (int j = i + 1; j < total; j++)
        {
            comparacoes++;
            if (comparaNomes(lista[j].nome, lista[menor].nome) < 0) menor = j;
        }
        if (menor != i)
        {
            aux = lista[i];
            lista[i] = lista[menor];
            lista[menor] = aux;
            movimentacoes += 3;
        }
    }
    printf("Lista ordenada por nome!\n");
    mostraContadores();
}

int main()
{
    int opcao;

    do
    {
        printf("\n===== FUNCIONARIOS (%d de %d) =====\n", total, MAX);
        printf("1 - Cadastrar (no final)\n2 - Inserir em uma posicao\n3 - Remover por CPF\n");
        printf("4 - Buscar por CPF\n5 - Ordenar por nome\n6 - Listar\n");
        printf("0 - Sair\n");
        opcao = lerNumero("Opcao: ");

        if (opcao == 1) inserir(total);
        else if (opcao == 2) inserir(lerNumero("Posicao (1 a total+1): ") - 1);
        else if (opcao == 3) remover();
        else if (opcao == 4) buscar();
        else if (opcao == 5) ordenar();
        else if (opcao == 6)
        {
            if (total == 0) printf("Ninguem cadastrado.\n");
            for (int i = 0; i < total; i++) mostraFicha(i);
        }
        else if (opcao != 0) printf("Opcao invalida!\n");
    } while (opcao != 0);

    return 0;
}
