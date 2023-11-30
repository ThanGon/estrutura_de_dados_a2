#include "pilha.h"
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void MaiorMenor(TPilha *p) {
    int maior = INT_MIN, menor = INT_MAX;
    TPilha *aux = inicializa(aux);
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
    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
}

// Função para ordenar uma pilha em ordem crescente
TPilha* ordena(TPilha *p) {
    TPilha *pilhaOrdenada = inicializa(pilhaOrdenada);

    while (!vazia(p)) {
        int temp = pop(p);

        // Caso informação retirada da pilha ordenada seja menor que o topo da pilha atual
        // Retirar o topo da pilha e reordena tudo
        while (!vazia(pilhaOrdenada) && pilhaOrdenada->topo->info < temp) {
            push(p, pop(pilhaOrdenada));
        }

        // Empilhar o elemento atual na pilha auxiliar
        push(pilhaOrdenada, temp);
    }

    return pilhaOrdenada;
}

// Preenche pilha com valores aleatorios
TPilha* preenchePilha(TPilha *p) {
    for (int i = 0; i < 10; i++)
    {
        push(p, rand());
    }
    
    return p;
}

void imprimePilha(TPilha *p) {
    TPilha *aux = inicializa(aux);
    aux->topo = p->topo;
    while (aux->topo != NULL) {
        printf("%d\n", aux->topo->info);
        aux->topo = aux->topo->prox;
    }
}

int main(void* args) {
    // Inicializa seed aleatoria
    srand(time(NULL));

    int opcao;
    TPilha *p = inicializa(p);
    p = preenchePilha(p);
    do
    {
        printf("\n\n");
        printf("1 - Maior e menor elemento da pilha\n");
        printf("2 - Ordenar pilha\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            MaiorMenor(p);
            break;
        case 2:
            p = ordena(p);
            imprimePilha(p);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 0);
    
    return 0;
}