#include <stdio.h>
#include <stdbool.h>
#include "matriz1.h"
#include "matriz2.h"

int main() {
    //vetor simples
    printf("Teste com vetor simples:\n");
    
    //criar
    Matriz* mat_simples = criar1(3, 3);

    //atribuir
    atribuir1(mat_simples, 0, 0, 1.0);
    atribuir1(mat_simples, 0, 1, 2.0);
    atribuir1(mat_simples, 0, 2, 3.0);
    atribuir1(mat_simples, 1, 0, 2.0);
    atribuir1(mat_simples, 1, 1, 4.0);
    atribuir1(mat_simples, 1, 2, 5.0);
    atribuir1(mat_simples, 2, 0, 3.0);
    atribuir1(mat_simples, 2, 1, 5.0);
    atribuir1(mat_simples, 2, 2, 6.0);

    //listar
    listar1(mat_simples);

    //é simétrica
    printf("\nÉ simétrica? \n");
    if (eh_simetrica1(mat_simples)) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }

    //transposta
    Matriz* transposta_simples = transposta1(mat_simples);
    printf("\nMatriz transposta (vetor simples):");
    listar1(transposta_simples);

    //liberar
    liberar1(mat_simples);
    liberar1(transposta_simples);

    //vetor de ponteiros
    printf("\nTeste com vetor de ponteiros:\n");

    //criar
    Matriz* mat_ponteiros = criar2(3, 3);

    //atribuir
    atribuir2(mat_ponteiros, 0, 0, 1.0);
    atribuir2(mat_ponteiros, 0, 1, 2.0);
    atribuir2(mat_ponteiros, 0, 2, 3.0);
    atribuir2(mat_ponteiros, 1, 0, 2.0);
    atribuir2(mat_ponteiros, 1, 1, 4.0);
    atribuir2(mat_ponteiros, 1, 2, 5.0);
    atribuir2(mat_ponteiros, 2, 0, 3.0);
    atribuir2(mat_ponteiros, 2, 1, 5.0);
    atribuir2(mat_ponteiros, 2, 2, 6.0);

    //listar
    listar2(mat_ponteiros);

    // é simétrica
    printf("\nÉ simétrica? \n");
    if (eh_simetrica2(mat_ponteiros)) {
        printf("A matriz é simétrica.\n");
    } else {
        printf("A matriz não é simétrica.\n");
    }
    //transposta
    Matriz* transposta_ponteiros = transposta2(mat_ponteiros);
    printf("\nMatriz transposta (vetor de ponteiros):");
    listar2(transposta_ponteiros);

    //liberar
    liberar2(mat_ponteiros);
    liberar2(transposta_ponteiros);

    return 0;
}
