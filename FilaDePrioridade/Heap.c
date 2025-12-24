#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *vetor;
    int capacidade;
    int tamanho;
}Heap;

Heap* inicializar(int capacidade){
    Heap *h = (Heap*) malloc(sizeof(Heap));
    if(h == NULL){
        fprintf(stderr, "Erro na alocação.\n");
        exit(1);
    }
    h->capacidade = capacidade;
    h->vetor = (int*) malloc(capacidade * sizeof(int));
    if(h->vetor == NULL){
        fprintf(stderr, "Erro na alocação do vetor.\n");
        free(h);
        exit(1);
    }
    h->tamanho = 0;

    return h;
}

static void sobeHeap(Heap *h, int i){
    int valor = h->vetor[i];
    while(i>0){
        int pai = (i-1)/2;
        if(h->vetor[pai] >= valor){
            break;
        }
        h->vetor[i] = h->vetor[pai];
        i = pai;
    }
    h->vetor[i] = valor;
}

static void desceHeap(Heap *h, int i, int n){
    int valor = h->vetor[i];
    while(2*i+1 < n){
        int filho = 2*i+1;
        if(filho+1 < n && h->vetor[filho] < h->vetor[filho + 1]){
            filho++;
        }
        if(valor >= h->vetor[filho]){
            break;
        }
        h->vetor[i] = h->vetor[filho];
        i = filho;
    }
    h->vetor[i] = valor;
}

void inserir(Heap *h, int valor){
    if(h->tamanho == h->capacidade){
        fprintf(stderr, "Heap Cheio.\n");
        return;
    }
    h->vetor[h->tamanho] = valor;
    sobeHeap(h, h->tamanho);
    h->tamanho++;
}

int removeMax(Heap *h){
    if(h->tamanho == 0){
        fprintf(stderr, "Heap Vazio.\n");
        return -1;
    }
    int max = h->vetor[0];
    h->vetor[0] = h->vetor[h->tamanho - 1];
    h->tamanho--;
    desceHeap(h,0,h->tamanho);
    return max;
}

void heapSort(Heap *h){
    int n = h->tamanho;
    for(int i = n-1; i>0; i--){
        int temp = h->vetor[0];
        h->vetor[0] = h->vetor[i];
        h->vetor[i] = temp;
        desceHeap(h,0,i);
    }
}