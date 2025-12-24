#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *v;
    int tam,cap;
}arrayDin;

void inicializa(arrayDin *a){
    a->v = (int *) malloc(1*sizeof(int));
    if(a->v == NULL){
        fprintf(stderr, "Falha na alocação de memória \n");
        exit(EXIT_FAILURE);
    }
    a->cap = 1;
    a->tam = 0;
}

static int cheio(arrayDin *a){
    return (a->tam == a->cap);
}

static void dobra(arrayDin *a){
    int *aux = (int *) realloc(a->v, (a->cap*2)*sizeof(int));
    if(!aux){
        fprintf(stderr, "Falha na realocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    a->v = aux;
    a->cap*=2;
}

static void divide(arrayDin *a){
    int *aux = (int *)realloc(a->v, (a->cap/2)*sizeof(int));
    if(aux == NULL){
        fprintf(stderr, "Falha na realocação de memória.\n");
        free(a->v);
        exit(EXIT_FAILURE);
    }
        a->v = aux;
        a->cap/=2;
}

void insere(arrayDin *a, int k){
    if(cheio(a)){
        dobra(a);
    }
    a->v[a->tam] = k;
    a->tam++;
}

void remove(arrayDin *a){
    if(a->tam == 0){
        return;
    }
    a->tam--;
    if(a->tam <= a->cap/4){
        divide(a);
    }
}

void imprime(arrayDin *a){
    int i;
    printf("[");
    for(i=0;i<a->tam;i++){
        printf("%d",a->v[i]);
        if(i<a->tam-1){
            printf(", ");
        }
    }
    printf("]\n");
}

void libera(arrayDin *a){
    free(a->v);
    a->v = NULL;
    a->tam = 0;
    a->cap = 0;
}