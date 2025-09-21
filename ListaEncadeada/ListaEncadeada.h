#ifndef LISTAENCADEADE_H
#define LISTAENCADEADA_H

typedef struct No{
    int chave;
    struct No *proximo;
}No;

typedef struct{
    No *cabeca;
}ListaEncadeada;

void imprime(ListaEncadeada *ld);
void inverter(ListaEncadeada *ld);
No* buscaOrdenada(ListaEncadeada *ld, int k);
void buscaInsercao(ListaEncadeada *ld, int k, No**atual, No**ant);
void insere(ListaEncadeada *ld, int k);
void insereOrdenado(ListaEncadeada *ld, int k);
void deletar(ListaEncadeada *ld, int k);
void liberar(ListaEncadeada *ld);

#endif