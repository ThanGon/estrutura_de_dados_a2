#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
    char nome[50];
    int salario;
    int imposto;
} funcionario;

typedef struct no {
	funcionario *info;
	struct no *prox;
    struct no *ant;
}NO;

int calculaImposto(int salario) {
    if (salario < 2700) {
        return 0;
    } else if (salario < 4200) {
        return 10;
    } else {
        return 20;
    }
}

NO* insere_lista_ordenada(NO* prim, funcionario *info, int decrescente) {
    NO* novo = (NO*) malloc(sizeof(NO));
    info->imposto = calculaImposto(info->salario);
    novo->info = info;

    if(prim == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }

    NO* aux = prim;
    // PERCORRE A LISTA ENCADEADA
    while(aux != NULL) {
        if (decrescente ? aux->info->salario < info->salario : aux->info->salario > info->salario) {
        // ao encontrar valor da lista menor que o valor inserido, insere no
            if (aux->ant == NULL) {
                novo->prox = aux;
                novo->ant = NULL;
                aux->ant = novo;
                return novo;
            } else {
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
                return prim;
            }
        } // caso percorra ate o fim sem encontrar valor insere no no final
        else if (aux->prox == NULL) {
            novo->prox = NULL;
            novo->ant = aux;
            aux->prox = novo;
            return prim;
        }
        aux = aux->prox;
    }
}

NO* busca_por_inicial(NO* prim, char nome) {
    NO* aux = prim;
    NO* resultado = NULL;
    while(aux != NULL) {
        if (aux->info->nome[0] == nome) {
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
        resultado = insere_lista_ordenada(resultado, aux->info, 0);
        aux = aux->prox;
    }
    return resultado;
}

void imprime_lista_detalhada(NO* prim) {
    if (prim == NULL) {
        printf("Lista vazia\n");
        return;
    }
    while (prim != NULL) {
        int salarioDescontado = prim->info->salario - (prim->info->salario * prim->info->imposto / 100);
        printf("Nome: %s | Salario: %i | Imposto: %i%% | Salario Descontado: %i\n", prim->info->nome, prim->info->salario, prim->info->imposto, salarioDescontado);
        prim = prim->prox;
    }
}

void imprime_lista(NO* prim) {
    if (prim == NULL) {
        printf("Lista vazia\n");
        return;
    }
    while (prim != NULL) {
        printf("Nome: %s | Salario: %i \n", prim->info->nome, prim->info->salario);
        prim = prim->prox;
    }
}

void imprime_lista_cima_baixo(NO* prim) {
    if (prim == NULL) {
        printf("Nenhum nome encontrado com esta inicial\n");
        return;
    }
    while (prim != NULL) {
        printf("Nome: %s | Salario: %i \n", prim->info->nome, prim->info->salario);
        prim = prim->ant;
    }
}