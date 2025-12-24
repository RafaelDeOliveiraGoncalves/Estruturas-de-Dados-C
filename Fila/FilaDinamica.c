#include <stdio.h>
#include <stdlib.h>
#include "../DequeDinamico/Deque.h"

typedef struct{
    DequeDin dq;
}FilaDinamica;

void inicializa(FilaDinamica *q){
    criarDequeDinamico(&q->dq);
}

void fila_esvazia(FilaDinamica *q){
    deque_esvaziar(&q->dq);
}

int fila_vazio(FilaDinamica *q){
    return deque_vazio(&q->dq);
}

void enfila(FilaDinamica *q, int k){
    inserirFim(&q->dq, k);
}

int desenfila(FilaDinamica *q){
    if(deque_vazio(&q->dq)){
        fprintf(stderr, "Fila Vazio.\n");
        return -1;
    }
    return removerInicio(&q->dq);
}

int frente(FilaDinamica *q){
    if(deque_vazio(&q->dq)){
        fprintf(stderr, "Fila Vazio.\n");
        return -1;
    }
    return retornarInicio(&q->dq);
}

void libera_fila(FilaDinamica *q){
    libera_deque(&q->dq);
}



