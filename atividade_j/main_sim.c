#include <stdio.h>
#include "matsim.h"

int main() {
    //criar
    MatSim* mat = criar(3);

    //atribuir
    atribuir(mat, 0, 0, 1.0);
    atribuir(mat, 0, 1, 2.0);
    atribuir(mat, 0, 2, 3.0);
    atribuir(mat, 1, 1, 4.0);
    atribuir(mat, 1, 2, 5.0);
    atribuir(mat, 2, 2, 6.0);

    //listar
    listar(mat);

    //acessar
    printf("\nValor na posição (2, 0): %.2f\n", acessar(mat, 2, 0));
    printf("Valor na posição (1, 2): %.2f\n", acessar(mat, 1, 2));

    //dimensao
    printf("\nDimensão da matriz: %d\n", dimensao(mat));

    //liberar memória
    liberar(mat);

    return 0;
}
