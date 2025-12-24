#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *v;
    int f,r,cap;
}Fila;

void fila_inicializa(Fila *q, int capacidade){
    q->v = malloc(capacidade * sizeof(int));
    if(!q->v){
        fprintf(stderr, "Erro na alocação da memória.\n");
        exit(EXIT_FAILURE);
    }
    q->f = -1;
    q->r = -1;
    q->cap = capacidade;
}

void esvazia(Fila *q){
    free(q->v);
    q->v = NULL;
    q->f = -1;
    q->r = -1;
}

int vazia(Fila *q){
    return(q->f == -1 && q->r== -1);
}

int cheia(Fila *q){
    return(((q->r+1)%q->cap)==q->f);
}

void enfila(Fila *q, int k){
    if(cheia(q)){
        fprintf(stderr, "Fila está cheia.\n");
        exit(1);
    }
    else if(vazia(q)){
        q->f = 0;
        q->r = 0;
    }
    else{
        q->r = ((q->r + 1)%q->cap);
    }
    q->v[q->r] = k;
}

int frente(Fila *q){
    if(vazia(q)){
        fprintf(stderr, "Fila está vazia.\n");
        exit(1);
    }
    return q->v[q->f];
}

int desenfila(Fila *q){
    if(vazia(q)){
        fprintf(stderr, "Fila está vazia.\n");
        exit(1);
    }
    int k = q->v[q->f];
    if(q->f == q->r){
        q->f = -1;
        q->r = -1;
    }
    else{
        q->f = ((q->f+1)%q->cap);
    }
    return k;
}

void imprime(Fila *q){
    if(vazia(q)){
        fprintf(stderr, "Fila está vazia.\n");
        exit(1);
    }
    int i = q->f;
    while(1){
        printf("%d ",q->v[i]);
        if(i==q->r){
            break;
        }
        i = (i+1)%q->cap;
    }
    printf("\n");
}