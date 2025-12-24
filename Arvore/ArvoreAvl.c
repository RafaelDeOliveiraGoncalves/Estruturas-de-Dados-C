#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int chave;
    struct No *le;
    struct No *ld;
    int altura;
}No;

typedef struct{
    No *raiz;
}ArvoreAvl;

No* criarNo(int chave){
    No *no = (No*) malloc(sizeof(No));
    if(no==NULL){
        fprintf(stderr, "Erro na alocação.\n");
        exit(1);
    }
    no->chave = chave;
    no->le = NULL;
    no->ld = NULL;
    no->altura = 0;
    
    return no;
}

static int maior(int a, int b){
    return (a>b) ? a : b;
}

int alturaNo(No *no){
    return (no==NULL) ? -1 : no->altura;
}

static int fatorBalanceamento(No *no){
    if(no!=NULL){
        return (alturaNo(no->le) - alturaNo(no->ld));
    }
    return 0;
}

static No* rotacaoEsquerda(No *no){
    No *y, *f;
    y = no->ld;
    f = y->le;

    y->le = no;
    no->ld = f;

    no->altura = (maior(alturaNo(no->le), alturaNo(no->ld))+1);
    y->altura = (maior(alturaNo(y->le), alturaNo(y->ld))+1);

    return y;
}

static No* rotacaoDireita(No *no){
    No *y, *f;
    y = no->le;
    f = y->ld;

    y->ld = no;
    no->le = f;

    no->altura = (maior(alturaNo(no->le), alturaNo(no->ld))+1);
    y->altura = (maior(alturaNo(y->le), alturaNo(y->ld))+1);

    return y;
}

static No* rotacaoDuplaEsquerda(No *no){
    no->ld = rotacaoDireita(no->ld);
    return rotacaoEsquerda(no);
}

static No* rotacaoDuplaDireita(No *no){
    no->le = rotacaoEsquerda(no->le);
    return rotacaoDireita(no);
}

static No* balancear(No *no){
    int fb = fatorBalanceamento(no);

    if(fb<-1 && fatorBalanceamento(no->ld)<=0){
        no = rotacaoEsquerda(no);
    }
    else if(fb>1 && fatorBalanceamento(no->le)>=0){
        no = rotacaoDireita(no);
    }
    else if(fb>1 && fatorBalanceamento(no->le)<0){
        no = rotacaoDuplaDireita(no);
    }
    else if(fb<-1 && fatorBalanceamento(no->ld)>0){
        no = rotacaoDuplaEsquerda(no);
    }
    return no;
}

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
    raiz->altura = (maior(alturaNo(raiz->le), alturaNo(raiz->ld))+1);
    raiz = balancear(raiz);
    return raiz;
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
    if(raiz != NULL){
        raiz->altura = (maior(alturaNo(raiz->le), alturaNo(raiz->ld))+1);
        raiz = balancear(raiz);
    }
    return raiz;
}

No* busca(No *raiz, int chave){
    No *p = raiz;
    while(p!=NULL && p->chave != chave){
        if(chave < p->chave){
            p = p->le;
        }
        else{
            p = p->ld;
        }
    }
    return p;
}

void preOrdem(No *no){
    if(no != NULL){
        printf("%d ", no->chave);
        preOrdem(no->le);
        preOrdem(no->ld);
    }
}

void inOrdem(No *no){
    if(no != NULL){
        inOrdem(no->le);
        printf("%d ", no->chave);
        inOrdem(no->ld);
    }
}

void posOrdem(No *no){
    if(no != NULL){
        posOrdem(no->le);
        posOrdem(no->ld);
        printf("%d ", no->chave);
    }
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

void imprimir(ArvoreAvl *arv){
    if(arv->raiz == NULL){
        printf("Árvore Vazia\n");
    }
    else{
        _imprimir(arv->raiz, 0);
        printf("\n");
    }
}