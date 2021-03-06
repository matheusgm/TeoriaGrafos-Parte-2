#include <stdlib.h>
#include <stdio.h>

/* n� da lista para armazenar valores reais */
typedef struct lista Lista;
struct lista {
    int info;
    Lista* prox;
};

typedef struct fila Fila;
struct fila{
    Lista* ini;
    Lista* fim;
};

Fila* fila_cria(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_insere(Fila *f, int v){
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n->info = v; /* armazena informa��o */
    n->prox = NULL; /* novo n� passa a ser o �ltimo */
    if (f->fim != NULL){ /* verifica se lista n�o estava vazia */
        f->fim->prox = n;
    } else{ /* fila estava vazia */
        f->ini = n;
    }
    f->fim = n;
}

int fila_vazia(Fila *f){
    return f->fim == NULL;
}

int fila_retira(Fila *f){
    Lista* t;
    int v;
    if (fila_vazia(f)){
        printf("Fila vazia.\n");
        exit(1);
    } /* aborta programa */
    t = f->ini;
    v = t->info;
    f->ini = t->prox;
    if (f->ini == NULL) /* verifica se fila ficou vazia */
        f->fim = NULL;
    free(t);
    return v;
}

void fila_libera(Fila *f){
    Lista* q = f->ini;
    while (q!=NULL) {
        Lista* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}









