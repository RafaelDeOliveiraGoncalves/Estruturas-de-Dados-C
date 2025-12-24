#ifndef DEQUEDINAMICO_H
#define DEQUEDINAMICO_H

typedef struct{
    int *vetor;
    int tam,cap, inicio,fim;
}DequeDin;

void criarDequeDinamico(DequeDin *dq);
int deque_cheio(DequeDin *dq);
int deque_vazio(DequeDin *dq);
void inserirInicio(DequeDin *dq, int k);
void inserirFim(DequeDin *dq, int k);
int removerInicio(DequeDin *dq);
int removerFim(DequeDin *dq);
void deque_esvaziar(DequeDin *dq);
int retornarInicio(DequeDin *dq);
int retornarFim(DequeDin *dq);
void libera_deque(DequeDin *dq);

#endif