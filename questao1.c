#include "lista_dupla_encadeada_funcionario.c"

NO* preencheLista(NO* prim) {
        for (int i = 0; i < 6; i++) {
        funcionario f;
        printf("Nome: ");
        scanf("%s", f.nome);
        printf("Salario: ");
        scanf("%i", &f.salario);
        prim = insere_lista_ordenada(prim, f, 1);
    }
    return prim;
}

NO* menu(int opcao, NO* prim) {
    switch (opcao)
    {
    case 1:
        funcionario f;
        printf("Nome: ");
        scanf("%s", f.nome);
        printf("Salario: ");
        scanf("%i", &f.salario);
        prim = insere_lista_ordenada(prim, f, 1);
        return prim;
    case 2:
        imprime_lista(prim);
        return prim;
    case 3:
        imprime_lista(ordena_lista_crescente(prim));
        return prim;
    case 4:
        char nome;
        printf("Insira a inicial: ");
        scanf(" %c", &nome);
        imprime_lista_cima_baixo(busca_por_inicial(prim, nome));
        return prim;
    default:
        return prim;
    }
}


int main() {
    NO* prim = NULL;
    printf("Insira 6 funcionarios:\n");
    prim = preencheLista(prim);
    printf("Lista iniciada\n");
    int opcao = 0;
    while (opcao != 5) {
        printf("Escolha uma das opções:\n");
        printf("1 - Inserir funcionario\n");
        printf("2 - Imprimir lista\n");
        printf("3 - Ordenar lista crescente\n");
        printf("4 - Buscar por inicial\n");
        printf("5 - Sair\n");
        scanf("%i", &opcao);
        prim = menu(opcao, prim);
    }
}