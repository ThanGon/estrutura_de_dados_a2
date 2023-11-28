#include "pilha.h"
#include <limits.h>
#include <string.h>

void MaiorMenor(TPilha *p) {
    int maior = INT_MIN, menor = INT_MAX;
    TPilha *aux = (TPilha*) malloc(sizeof(TPilha));
    aux->topo = p->topo;
    while (aux->topo != NULL) {
        if (aux->topo->info > maior) {
            maior = aux->topo->info;
        }
        if (aux->topo->info < menor) {
            menor = aux->topo->info;
        }
        aux->topo = aux->topo->prox;
    }
}

// Função para ordenar uma pilha em ordem crescente
TPilha* ordena(TPilha *p) {
    TPilha *pilhaOrdenada = inicializa(pilhaOrdenada);

    while (!vazia(p)) {
        int temp = pop(p);

        // Caso informação retirada da pilha ordenada seja menor que o topo da pilha atual
        // Retirar o topo da pilha ordenada e empilhar na pilha atual
        if (!vazia(pilhaOrdenada) && pilhaOrdenada->topo->info > temp) {
            push(p, pop(pilhaOrdenada));
        }

        // Empilhar o elemento atual na pilha auxiliar
        push(pilhaOrdenada, temp);
    }

    return pilhaOrdenada;
}

// TPilha* ordena(TPilha *p) {
//     TPilha *aux = NULL;
//     TPilha *resultado = NULL;
//     aux = inicializa(aux);
//     resultado = inicializa(resultado);
    
//     aux->topo = p->topo;
//     while (aux->topo != NULL) {
//         TPilha *topo = aux;
//         while (aux -> topo -> prox != NULL) {
//             if (aux->topo->info > aux->topo->prox->info) {
//                 push(resultado, aux->topo->prox->info);
//             }
//             aux->topo = aux->topo->prox;
//         }
//         aux->topo = topo->topo->prox;
//     }
//     return resultado;
// }