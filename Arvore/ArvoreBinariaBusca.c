#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *le;
    struct No *ld;
}No;

No* criarNo(int chave){
    No* no = (No*) malloc(sizeof(No));
    if(no==NULL){
            fprintf(stderr, "Erro na alocação.\n");
            exit(1);
        }
    no->chave = chave;
    no->le = NULL;
    no->ld = NULL;
    return no;
}

typedef struct{
    No *raiz;
}Arvore;

No* insere(No *raiz, int chave){
    if(raiz == NULL){
        return criarNo(chave);
    }
    else{
        if(chave < raiz->chave){
            raiz->le = insere(raiz->le, chave);
        }
        else if(chave > raiz->chave){
            raiz->ld = insere(raiz->ld, chave);
        }
    }
    return raiz;
}

No* busca(No *raiz, int chave){
    No *p = raiz;
    while(p != NULL && p->chave != chave){
        if(chave < p->chave){
            p = p->le;
        }
        else{
            p = p->ld;
        }
    }
    return p;
}

No* remover(No *raiz, int chave){
    if(raiz == NULL){
        return NULL;
    }
    if(chave < raiz->chave){
        raiz->le = remover(raiz->le, chave);
    }
    else if(chave > raiz->chave){
        raiz->ld = remover(raiz->ld, chave);
    }
    else{ //Nó encontrado
        if(raiz->le == NULL){
            No *aux = raiz->ld;
            free(raiz);
            return aux;
        }
        else if(raiz->ld == NULL){
            No *aux = raiz->le;
            free(raiz);
            return aux;
        }
        No *aux = raiz->le;
        while(aux->ld != NULL){
            aux = aux->ld;
        }
        raiz->chave = aux->chave;
        raiz->le = remover(raiz->le,aux->chave);
    }
    return raiz;
}

void preOrdem(No *raiz){
    if(raiz != NULL){
        printf("%d ",raiz->chave);
        preOrdem(raiz->le);
        preOrdem(raiz->ld);
    }
}

void inOrdem(No *raiz){
    if(raiz != NULL){
        inOrdem(raiz->le);
        printf("%d ",raiz->chave);
        inOrdem(raiz->ld);
    }
}

void posOrdem(No *raiz){
    if(raiz != NULL){
        posOrdem(raiz->le);
        posOrdem(raiz->ld);
        printf("%d ",raiz->chave);
    }
}

int altura(No *raiz){
    if(raiz == NULL) return -1;

    int alturaEsq = 0;
    int alturaDir = 0;
    if(raiz->le != NULL){
        alturaEsq = altura(raiz->le);
    }
    if(raiz->ld != NULL){
        alturaDir = altura(raiz->ld);
    }
    return (alturaEsq > alturaDir) ? alturaEsq+1 : alturaDir+1;
}

int qtdNos(No *raiz){
    if(raiz == NULL){
        return 0;
    }
    return 1 + qtdNos(raiz->le) + qtdNos(raiz->ld);
}

void liberarArvore(No *raiz){
    if(raiz != NULL){
        liberarArvore(raiz->le);
        liberarArvore(raiz->ld);
        free(raiz);
    }
}

static void _imprimir(No *raiz, int nivel){
    if(raiz == NULL){
        return;
    }
    _imprimir(raiz->ld, nivel+1);
    printf("\n");
    for(int i=0; i<nivel; i++){
        printf("\t");
    }
    printf("%d\n",raiz->chave);
    _imprimir(raiz->le, nivel+1);
}

void imprimir(Arvore *arv){
    if(arv->raiz == NULL){
        printf("Árvore Vazia\n");
    }
    else{
        _imprimir(arv->raiz, 0);
        printf("\n");
    }
}