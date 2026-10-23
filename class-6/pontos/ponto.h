#ifndef PONTO_H
#define PONTO_H

// criacao de funcoes que serao empregadas no codigo em C
typedef struct ponto Ponto;

Ponto* criar_ponto(float x, float y);
void acessar_ponto(Ponto* p, float* x, float* y);
void atribuir_valores(Ponto* p, float x, float y);
void liberar_ponto(Ponto* p);
float calcular_distancia(Ponto* p1, Ponto* p2);

#endif