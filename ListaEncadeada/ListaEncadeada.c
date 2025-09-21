#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *proximo;
}No;

typedef struct{
    No *cabeca;
}ListaEncadeada;

ListaEncadeada ld = { .cabeca = NULL};

void imprime(ListaEncadeada *ld){
    No *p = ld->cabeca;
    while(p!=NULL){
        printf("%d->",p->chave);
        p = p->proximo;
    } 
    printf("NULL\n");
}

void inverter(ListaEncadeada *ld){
    No *p = ld->cabeca;
    No *r = NULL;
    No *t;
    while(p!=NULL){
        t = p->proximo;
        p->proximo = r;
        r = p;
        p = t;
    }
    ld->cabeca = r;
}

No* buscaOrdenada(ListaEncadeada *ld, int k){
    No *atual = ld->cabeca;
    while(atual!=NULL && atual->chave < k){
        atual = atual->proximo;
    }
    return atual;
}

void buscaInsercao(ListaEncadeada *ld, int k, No**atual, No**ant){
    *atual = ld->cabeca;
    *ant = NULL;
    while(*atual!=NULL && (*atual)->chave < k){
        *ant = *atual;
        *atual = (*atual)->proximo;
    }
}

void insere(ListaEncadeada *ld, int k){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        fprintf(stderr, "Erro na alocação.\n");
        exit(1);
    }
    novo->chave = k;
    novo->proximo = ld->cabeca;
    ld->cabeca = novo;
}

void insereOrdenado(ListaEncadeada *ld, int k){
    No* atual, *ant;
    buscaInsercao(ld,k,&atual,&ant);
    No* novo = malloc(sizeof(No));
    if(novo == NULL){
        fprintf(stderr, "Erro na alocação\n");
        exit(1);
    }
    novo->chave = k;
    if(ant==NULL){
        novo->proximo = ld->cabeca;
        ld->cabeca = novo;
    }
    else{
        novo->proximo = atual;
        ant->proximo = novo;
    }
}

void deletar(ListaEncadeada *ld, int k){
    No *atual, *ant;
    buscaInsercao(ld,k,&atual,&ant);
    if(atual==NULL){
        return;
    }
    if(ant == NULL){
        ld->cabeca = atual->proximo;
    }
    else{
        ant->proximo = atual->proximo;
    }
    free(atual);
}

void liberar(ListaEncadeada *ld){
    No *p = ld->cabeca;
    while(p!=NULL){
        No *t = p->proximo;
        free(p);
        p=t;
    }
    ld->cabeca = NULL;
}

