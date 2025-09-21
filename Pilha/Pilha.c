#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *v;
    int cap, topo;
}Pilha;

void inicializa(Pilha *p, int capacidade){
    p->cap = capacidade;
    p->topo = 0;
    p->v = (int *) malloc(capacidade * sizeof(int));
    if(p->v == NULL){
        fprintf(stderr, "Erro ou alocar memória\n");
        exit(EXIT_FAILURE);
    }
}

void esvazia(Pilha *p){
    free(p->v);
    p->v = NULL;
    p->topo = 0;
}

int vazia(Pilha *p){
    return (p->topo == 0);
}

int cheia(Pilha *p){
    return (p->topo == p->cap);
}

void empilha(Pilha *p, int k){
    if(cheia(p)){
        fprintf(stderr, "Pilha está cheia.\n");
        exit(EXIT_FAILURE);
    }
    p->v[p->topo] = k;
    p->topo++;
}

int desempilha(Pilha *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia\n");
        exit(EXIT_FAILURE);
    }
    p->topo--;
    return p->v[p->topo];
}

int topo(Pilha *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia\n");
        exit(EXIT_FAILURE);
    }
    return p->v[p->topo-1];
}

