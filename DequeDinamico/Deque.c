#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vetor;
    int tam,cap, inicio,fim;
}DequeDin;

void criarDequeDinamico(DequeDin *dq){
    dq->vetor = malloc(2*sizeof(int));
    if(dq->vetor == NULL){
        fprintf(stderr, "Falha na alocação do vetor.\n");
        exit(1);
    }
    dq->tam =0;
    dq->cap = 2;
    dq->inicio = 0;
    dq->fim = 0;
}

int deque_cheio(DequeDin *dq){
    return dq->tam == dq->cap;
}

int deque_vazio(DequeDin *dq) {
    return dq->tam == 0;
}

static void realocar(DequeDin *dq, int novaCap){
    int *aux = (int*) malloc(novaCap * sizeof(int));
    if(aux == NULL){
        fprintf(stderr, "Falha na realocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<dq->tam; i++){
        aux[i] = dq->vetor[(dq->inicio + i) % dq->cap];
    }
    free(dq->vetor);
    dq->vetor = aux;
    dq->inicio = 0;
    dq->fim = dq->tam;
    dq->cap = novaCap;
}

void inserirInicio(DequeDin *dq, int k){
    if(deque_cheio(dq)){
        realocar(dq,dq->cap*2);
    }
    dq->inicio = (dq->inicio -1 + dq->cap) % dq->cap;
    dq->vetor[dq->inicio] = k;
    dq->tam++;
}

void inserirFim(DequeDin *dq, int k){
    if(deque_cheio(dq)){
        realocar(dq,dq->cap*2);
    }
    dq->vetor[dq->fim] = k;
    dq->fim = (dq->fim + 1) % dq->cap;
    dq->tam++;
}

int removerInicio(DequeDin *dq){
    if(dq->tam == 0){
        fprintf(stderr, "Deque Vazio.\n");
        return -1;
    }
    int valor = dq->vetor[dq->inicio];
    dq->inicio = (dq->inicio + 1) % dq->cap;
    dq->tam--;
    if (dq->tam > 0 && dq->tam <= dq->cap / 4 && dq->cap > 2) {
        realocar(dq,dq->cap/2);
    }
    return valor;
}

int removerFim(DequeDin *dq){
    if(dq->tam == 0){
        fprintf(stderr, "Deque Vazio.\n");
        return -1;
    }
    dq->fim = (dq->fim -1 + dq->cap) % dq->cap;
    int valor = dq->vetor[dq->fim];
    dq->tam--;
    if (dq->tam > 0 && dq->tam <= dq->cap / 4 && dq->cap > 2) {
        realocar(dq,dq->cap/2);
    }
    return valor;
}

int retornarInicio(DequeDin *dq){
    if(dq->tam == 0){
        fprintf(stderr, "Deque Vazio.\n");
        return -1;
    }
    return dq->vetor[dq->inicio];
}

int retornarFim(DequeDin *dq){
    if(dq->tam == 0){
        fprintf(stderr, "Deque Vazio.\n");
        return -1;
    }
    return dq->vetor[(dq->fim -1 + dq->cap) % dq->cap];
}

void deque_esvaziar(DequeDin *dq){
    dq->tam = 0;
    dq->inicio = 0;
    dq->fim = 0;
}

void libera_deque(DequeDin *dq){
    if(dq != NULL){
        free(dq->vetor);
        dq->vetor = NULL;
    }
}

