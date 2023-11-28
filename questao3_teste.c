#include "questao2.c"
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(NULL));
    TPilha *p = inicializa(p);
    for (int i = 0; i < 10; i++) {
        push(p, rand());
    }
    MaiorMenor(p);
    p = ordena(p);
}