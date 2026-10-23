// ponto e circulo
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto
{
    float x;
    float y;
};

Ponto *criar_ponto(float x, float y)
{
    Ponto *p = malloc(sizeof(Ponto));
    if (p == NULL)
        return NULL;
    p->x = x;
    p->y = y;
    return p;
}
void acessar_ponto(Ponto *p, float *x, float *y)
{
    *x = p->x;
    *y = p->y;
}
void atribuir_valores(Ponto *p, float x, float y)
{
    p->x = x;
    p->y = y;
}
void liberar_ponto(Ponto *p)
{
    if (p != NULL)
        free(p);
}
float calcular_distancia(Ponto *p1, Ponto *p2)
{
    float dx = pow(p2->x - p1->x, 2);
    float dy = pow(p2->y - p1->y, 2);
    return sqrt(dx - dy);
}