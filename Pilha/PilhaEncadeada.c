#include <stdio.h>
#include <stdlib.h>
#include "../ListaEncadeada/ListaEncadeada.h"

typedef struct{
    ListaEncadeada *lista;
}PilhaEncadeada;

void pilha_inicializa(PilhaEncadeada *p){
    p->lista = malloc(sizeof(ListaEncadeada));
    if(!p->lista){
        fprintf(stderr, "Erro na alocação da lista.\n");
        exit(EXIT_FAILURE);
    }
    p->lista->cabeca = NULL;
}

void esvazia(PilhaEncadeada *p){
    while (!vazia(p)) {
        No *aux = p->lista->cabeca;
        p->lista->cabeca = aux->proximo;
        free(aux);
    }
}

int vazia(PilhaEncadeada *p){
    return (p->lista->cabeca == NULL);
}

void empilha(PilhaEncadeada *p, int k){
    insere(p->lista,k);
}

int desempilha(PilhaEncadeada *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia.\n");
        exit(1);
    }
    No *no = p->lista->cabeca;
    int k = no->chave;
    p->lista->cabeca = no->proximo;
    free(no);
    return k;
}

int topo(PilhaEncadeada *p){
    if(vazia(p)){
        fprintf(stderr, "Pilha está vazia");
        exit(1);
    }
    return p->lista->cabeca->chave;
}

void imprime_pilha(PilhaEncadeada *p){
    No *no = p->lista->cabeca;
    while(no!=NULL){
        printf("%d\n",no->chave);
        no = no->proximo;
    }
}
