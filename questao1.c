#include "lista_dupla_encadeada_funcionario.c"

int main() {
    NO* prim = NULL;
    for (int i = 0; i < 6; i++) {
        funcionario f;
        printf("Nome: ");
        scanf("%s ", f.nome);
        printf("Salario: ");
        scanf("%i ", &f.salario);
        prim = insere_lista_ordenada(prim, f, 1);
    }
    imprime_lista(prim);
}