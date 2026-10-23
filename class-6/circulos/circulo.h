#ifndef CIRCULO_H
#define CIRCULO_H

typedef struct circulo Circulo;
Circulo* criar_circulo(float raio, float origem);
void atribuir_valores(Circulo* c, float* raio, float* origem);
void esta_dentro_do_circulo(float raio, float origem);
void liberar_circulo();

#endif