#include "fila.h"

typedef struct aviao {
    int id;
    char nome[25];
} aviao;

int tamanhoFilaEspera(TFila *filaEspera) {
    int tamanho = 0;
    NO *aux = filaEspera->inicio;
    while (aux != NULL)
    {
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}

int buscaAviaoPorId(int id, aviao avioes[]) {
    for (int i = 0; i < 6; i++)
    {
        if (avioes[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void adicionarAviaoFila(TFila *f, int idAviao, aviao avioes[]) {
    NO *aux = f->inicio;
    while (aux != NULL)
    {
        if (aux->info == idAviao)
        {
            printf("Aviao ja esta na fila de espera\n");
            return;
        }
        aux = aux->prox;
    }

    if (buscaAviaoPorId(idAviao, avioes) == -1)
    {
        printf("Aviao nao encontrado\n");
        return;
    }

    inserir(f, idAviao);
}



void liberarAviao(TFila *f) {
    if (vazia(f))
    {
        printf("Nao ha avioes na fila de espera\n");
    }
    else
    {
        printf("Aviao identificado por: %d liberado para decolagem\n", f->inicio->info);
        remover(f);
    }
}

void listarAvioes(TFila *f) {
    if (vazia(f))
    {
        printf("Nao ha avioes na fila de espera\n");
    }
    else
    {
        printf("Avioes na fila de espera:\n");
        NO *aux = f->inicio;
        while (aux != NULL)
        {
            printf("Aviao identificado por: %d\n", aux->info);
            aux = aux->prox;
        }
    }
}


int main(void* args) {
    TFila *filaEspera = inicializa(filaEspera);
    aviao avioes[6] = {1, "Aviao 1", 2, "Aviao 2", 3, "Aviao 3", 4, "Aviao 4", 5, "Aviao 5", 6, "Aviao 6"};

    int opcao = 9;
    while (opcao != 0)
    {
        printf("\n\n");
        printf("1 - Inserir aviao na fila de espera\n");
        printf("2 - Liberar primeiro aviao da fila para decolagem\n");
        printf("3 - Listar avioes na fila de espera\n");
        printf("4 - Numero de avioes na fila de espera\n");
        printf("5 - Caracteristicas do primeiro aviao na fila de espera\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o id do aviao: ");
            int id;
            scanf("%d", &id);
            adicionarAviaoFila(filaEspera, id, avioes);
            break;
        case 2:
            liberarAviao(filaEspera);
            break;
        case 3:
            listarAvioes(filaEspera);
            break;
        case 4:
            printf("Numero de avioes na fila de espera: %d\n", tamanhoFilaEspera(filaEspera));
            break;
        case 5: 
            if (filaEspera->inicio != NULL) {
                int index = buscaAviaoPorId(filaEspera->inicio->info, avioes);
                aviao a = avioes[index];
                printf("Id: %d | Nome: %s", a.id, a.nome);
            } else {
                printf("Nao ha avioes na fila de espera\n");
            }
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }

    return 0;
}


