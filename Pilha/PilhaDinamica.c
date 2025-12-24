#include <stdio.h>
#include <stdlib.h>
#include "../ArrayDinamico/arrayDin.h"

typedef struct{
    arrayDin array;
}PilhaDinamica;

void pilha_inicializa(PilhaDinamica *p){
    inicializa(&p->array);
}

void esvazia(PilhaDinamica *p){
    p->array.tam = 0;
}

int vazia(PilhaDinamica *p){
    return(p->array.tam == 0);
}

void empilha(PilhaDinamica *p, int k){
    insere(&p->array, k);
}

int desempilha(PilhaDinamica *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    int k = p->array.v[p->array.tam - 1];
    remove(&p->array);
    return k;
}

int topo(PilhaDinamica *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia.\n");
        exit(EXIT_FAILURE);
    }
    return p->array.v[p->array.tam - 1];
}

void libera_pilha(PilhaDinamica *p) {
    libera(&p->array);
}

void imprime_pilha(PilhaDinamica *p){
    if(vazia(p)){
        printf("Pilha Vazia\n");
        return;
    }
    printf("Topo\n");
    for(int i = p->array.tam - 1; i>=0; i--){
        printf("%d\n",p->array.v[i]);
    }
}