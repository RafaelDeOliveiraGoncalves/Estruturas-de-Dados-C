#include <stdio.h>
#include <stdlib.h>
#include "../ArrayDinamico/arrayDin.h"

typedef struct{
    arrayDin array;
    int topo;
}PilhaDinamica;

void pilha_inicializa(PilhaDinamica *p){
    inicializa(&p->array);
    p->topo = -1;
}

void esvazia(PilhaDinamica *p){
    libera(&p->array);
    p->topo = -1;
}

int vazia(PilhaDinamica *p){
    return(p->topo == -1);
}

void empilha(PilhaDinamica *p, int k){
    insere(&p->array, k);
    p->topo++;
}

int desempilha(PilhaDinamica *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    int k = p->array.v[p->topo];
    deleta(&p->array);
    p->topo--;
    return k;
}

int topo(PilhaDinamica *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    return p->array.v[p->topo];
}