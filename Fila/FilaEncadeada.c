#include <stdio.h>
#include <stdlib.h>
#include "../ListaEncadeada/ListaEncadeada.h"

typedef struct{
    ListaEncadeada *lista;
    No *r;
}FilaEncadeada;

void inciliza_fila(FilaEncadeada *q){
    q->lista = (ListaEncadeada*) malloc(sizeof(ListaEncadeada));
    if (q->lista == NULL) {
        exit(EXIT_FAILURE);
    }
    q->lista->cabeca = NULL;
    q->r = NULL;
}

void esvazia(FilaEncadeada *q){
    while(!vazia(q)){
        desenfila(q);
    }
}

int vazia(FilaEncadeada *q){
    return (q->lista->cabeca == NULL);
}

void enfila(FilaEncadeada *q, int k){
    No *p = (No*) malloc(sizeof(No));
    if(p == NULL) exit(EXIT_FAILURE);
    p->chave = k;
    p->proximo = NULL;
    if(vazia(q)){
        q->lista->cabeca = p;
        q->r = p;
    }
    else{
        q->r->proximo = p;
        q->r = p;
    }
}

int desenfila(FilaEncadeada *q){
    if(vazia(q)){
        fprintf(stderr, "A Fila está vazia.\n");
    }
    No *p = q->lista->cabeca;
    int k = p->chave;
    q->lista->cabeca = q->lista->cabeca->proximo;
    if(vazia(q)){
        q->r = NULL;
    }
    free(p);
    return k;
}

int frente(FilaEncadeada *q){
    if(vazia(q)){
        fprintf(stderr, "A Fila está vazia.\n");
    }
    return q->lista->cabeca->chave;
}

void imprimir(FilaEncadeada *q){
    No *p = q->lista->cabeca;
    printf("%s ","Start ->");
    while(p!=NULL){
        printf("%d | ",p->chave);
        p = p->proximo;
    }
    printf("%s ","<- End");
}