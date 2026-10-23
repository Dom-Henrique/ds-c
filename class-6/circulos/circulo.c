#include <stdio.h>
#include <stdlib.h>
#include <ponto.h>
#include "circulo.h"

struct circulo
{
    float raio;
    float d1;
    float d2;
};

Circulo *criar_circulo(float raio, float d1, float d2)
{
    Circulo *c = malloc(sizeof(Circulo));
    if (c == NULL)
        return NULL;
    c->d1 = d1;
    c->d2 = d2;
    c->raio = raio;
    return c;
}
void atribuir_valores(Circulo *c, float *raio, float *d1, float *d2)
{
    *raio = c->raio;
    *d1 = c->d1;
    *d2 = c->d2;
}
int esta_dentro_do_circulo(float *raio, float *d1, float *d2)
{
    float equacao = calcular_distancia(d1, d2);
    if (equacao <= *raio)
        return 1;
    return 0;
}
void liberar_circulo(Circulo* c){
    if(c!=NULL) free(c);
}