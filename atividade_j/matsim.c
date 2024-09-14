#include <stdio.h>
#include <stdlib.h>
#include "matsim.h"

MatSim* criar(int n){ 
    int s = n*(n+1)/2;

    MatSim* mat = (MatSim*)malloc(sizeof(MatSim)); 
    mat->dim = n; 
    mat->v = (float*)malloc(s * sizeof(float)); 

    return mat; 
} 

float acessar(MatSim* mat, int i, int j){ 
    int k; 
    if (i<0 || i>=mat->dim || j<0 || j>=mat->dim){ 
        printf("Acesso inválido!\n"); 
        exit(1); 
    } 

    if (i>=j) 
    k = i*(i+1)/2 + j; 
    else 
    k = j*(j+1)/2 + i; 

    return mat->v[k]; 
}

void atribuir(MatSim* mat, int i, int j, float v){
    int k; 
    if (i<0 || i>=mat->dim || j<0 || j>=mat->dim) {
        printf("Atribuição inválida!\n");
        exit(1);
    }
 
    if (i>=j) 
    k = i*(i+1)/2 + j; 
    else 
    k = j*(j+1)/2 + i; 

    mat->v[k] = v; 
}

int dimensao(MatSim* mat){
    return mat->dim;
}

void listar(MatSim* mat){
    printf("\nMatriz: \n\n");
    for(int i = 0; i < mat->dim; i++){
        for(int j = 0; j < mat->dim; j++){
            printf(" %d", (int)acessar(mat, i, j));
        }
        printf("\n");
    }
}

void liberar(MatSim* mat){
    free(mat->v);
    free(mat);
}

