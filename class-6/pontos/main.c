#include <stdio.h>
#include <stdlib.h>
#include <ponto.h>

int main()
{
    Ponto *p1 = criar_ponto(10, 20);
    acessar_ponto(p1, 10, 20);
    atribuir_valores(p1, 10, 20);
    Ponto *p2 = criar_ponto(20, 40);
    acessar_ponto(p2, 20, 40);
    atribuir_valores(p1, 20, 40);
    float distancia = calcular_distancia(p1, p2);
    printf("Distancia: %f", distancia);
    liberar_ponto(p1);
    liberar_ponto(p2);
}