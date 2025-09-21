#ifndef ARRAYDIN_H
#define ARRAYDIN_H

typedef struct{
    int *v;
    int tam,cap;
}arrayDin;

void inicializa(arrayDin *a);
void insere(arrayDin *a, int k);
void deleta(arrayDin *a);
void imprime(arrayDin *a);
void libera(arrayDin *a);

#endif