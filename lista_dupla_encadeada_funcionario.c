#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    char nome[50];
    int salario;
} funcionario;

typedef struct no {
	funcionario info;
	struct no *prox;
    struct no *ant;
}NO;


NO* inserir_inicio(NO *prim, funcionario info){
    NO *novo = (NO*) malloc(sizeof(NO));

    novo->info = info;
    novo->prox = prim;
    novo->ant = NULL;

    if(prim != NULL){
        prim->ant = novo;
    }

    return novo;
}


// NO* inserir_final(NO *prim, funcionario info){
//     NO *novo = (NO*) malloc(sizeof(NO));

//     novo->info = info;
//     novo->prox = NULL;

//     if(prim == NULL){
//         novo->ant = NULL;
//         return novo;
//     }

//     NO *aux = prim;
//     while(aux->prox != NULL){
//         aux = aux->prox;
//     }
//     aux->prox = novo;
//     novo->ant = aux;
//     return prim;
// }

NO* insere_lista_ordenada(NO* prim, funcionario info, int decrescente) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->info = info;

    if(prim == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }

    NO* aux = prim;
    while(aux->prox != NULL && (decrescente ? aux->info.salario > info.salario : aux->info.salario < info.salario)) {
        aux = aux->prox;
    }

    if(aux->ant == NULL) {
        novo->ant = NULL;
        novo->prox = aux;
        aux->ant = novo;
        return novo;
    }

    novo->prox = aux;
    novo->ant = aux->ant;
    aux->ant->prox = novo;
    aux->ant = novo;
    return prim;
}

NO* busca_por_inicial(NO* prim, char nome) {
    NO* aux = prim;
    NO* resultado = NULL;
    while(aux != NULL) {
        if (strcmp(aux->info.nome[0], nome) != 0) {
            if (resultado == NULL) {
                resultado = (NO*) malloc(sizeof(NO));
                resultado->prox = NULL;
                resultado->ant = NULL;
            } else {
                resultado->prox = (NO*) malloc(sizeof(NO));
                resultado->prox->ant = resultado;
                resultado = resultado->prox;
                resultado->prox = NULL;
            }
            resultado->info = aux->info;
        }
        aux = aux->prox;
    }
    return resultado;
}

NO* ordena_lista_crescente(NO* prim) {
    NO* aux = prim;
    NO* resultado = NULL;
    while(aux != NULL) {
        resultado = insere_lista_ordenada(resultado, aux->info, 1);
        aux = aux->prox;
    }
    return resultado;
}

void imprime_lista(NO* prim) {
    if (prim == NULL) {
        printf("Lista vazia\n");
        return;
    }
    while (prim != NULL) {
        printf("Nome: %s | Salario: %i \n", prim->info.nome, prim->info.salario);
        prim = prim->prox;
    }
}