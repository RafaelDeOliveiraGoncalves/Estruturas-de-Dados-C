#ifndef FILADINAMICA_H
#define FILADINAMICA_H

#include "../DequeDinamico/Deque.h"

typedef struct{
    DequeDin dq;
}FilaDinamica;

void inicializa(FilaDinamica *q);
void fila_esvazia(FilaDinamica *q);
int fila_vazio(FilaDinamica *q);
void enfila(FilaDinamica *q, int k);
int desenfila(FilaDinamica *q);
int frente(FilaDinamica *q);
void libera_fila(FilaDinamica *q);

#endif