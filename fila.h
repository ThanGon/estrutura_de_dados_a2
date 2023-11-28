#include <stdio.h>
#include <stdlib.h>

// Representa cada nó da minha fila
typedef struct no {
    // Representa a informação que desejo armazenar (info como inteiro no exemplo, mas na prática pode ser o que vc quiser)
	int info;
    // Ponteiro que irá armazenar o endereço do próximo nó.
	struct no *prox;
}NO;

typedef struct fila{
    NO *inicio;
    NO *fim;
}TFila;

// Criar uma fila vazia;
TFila *inicializa(TFila *f){
    f = (TFila*) malloc(sizeof(TFila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Verifica se a fila está vazia 
int vazia(TFila *f){
    if(f->inicio == NULL && f->fim == NULL){
        return 1;
    } else {
        return 0;
    }
}

// Inserir elemento na fila
void inserir(TFila *f, int info){
    // Alocação de um NÓ na memória
    NO *novo = (NO*) malloc(sizeof(NO));
    
    // Preenche os campos do NÓ
    novo->info = info;
    novo->prox = NULL;

    // Encadeamento na fila
    if(vazia(f)){
        f->inicio = novo;
    } else {
        // O último nó passa a apontar para o novo nó;
        f->fim->prox = novo;
    }

    // O último nó passa a ser o novo nó
    f->fim = novo;
}

int remover(TFila *f){
    // Se a fila estiver vazia
    if(vazia(f)){
        return -1;
    }

    NO *aux = NULL;
    // Caso a fila possua UM elemento
    if(f->inicio == f->fim){
        aux = f->inicio;
        f->inicio = NULL;
        f->fim = NULL;
    } else { // Caso possua mais de um elemento
        aux = f->inicio;
        f->inicio = f->inicio->prox;
    }

    int info = aux->info;
    free(aux);
    return info;
}

void libera(TFila *f){
    while (!vazia(f)){
        remover(f);
    }
}