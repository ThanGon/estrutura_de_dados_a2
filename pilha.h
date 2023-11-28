#include <stdio.h>
#include <stdlib.h>

// Representa cada nó da minha fila
typedef struct no {
    // Representa a informação que desejo armazenar (info como inteiro no exemplo, mas na prática pode ser o que vc quiser)
	int info;
    // Ponteiro que irá armazenar o endereço do próximo nó.
	struct no *prox;
}NO;

typedef struct pilha{
    NO *topo;
}TPilha;

// Criar uma pilha vazia;
TPilha *inicializa(TPilha *p){
    p = (TPilha*) malloc(sizeof(TPilha));
    p->topo = NULL;
    return p;
}

// Verifica se a pilha está vazia 
int vazia(TPilha *p){
    if(p->topo == NULL){
        return 1;
    } else {
        return 0;
    }
}

// Inserir elemento na pilha
void push(TPilha *p, int info){
    // Alocação de um NÓ na memória
    NO *novo = (NO*) malloc(sizeof(NO));
    
    // Preenche os campos do NÓ
    novo->info = info;
    novo->prox = p->topo;

    // Atualizar o topo
    p->topo = novo;
}

int pop(TPilha *p){
    // Se a pilha estiver vazia
    if(vazia(p)){
        return -1;
    }

    NO *aux = NULL;
    aux = p->topo;

    // Atualiza o topo
    p->topo = p->topo->prox;

    int info = aux->info;
    free(aux);
    return info;
}

void libera(TPilha *p){
    while (!vazia(p)){
        pop(p);
    }
}