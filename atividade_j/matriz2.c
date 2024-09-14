//matriz com vetor de ponteiros

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "matriz2.h"

struct matriz{
    int lin;
    int col;
    float** v;
};

Matriz* criar2(int m, int n){
    // aloca a estrutura
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    if(mat == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    mat->lin = m;
    mat->col = n;
    //aloca um vetor de ponteiros p/ cada linha
    mat->v = (float**)malloc(m* sizeof(float*));
    for(int i = 0; i<m; i++){
        // aloca p/ cada linha com n colunas
        mat->v[i] = (float*) malloc(n*sizeof(float));
    }
    return mat;
}

void liberar2(Matriz* mat){
    for(int i =0; i<mat->lin; i++){
        free(mat->v[i]);// libera as linhas (cada vetor de n floats)
    }
    free(mat->v);
    free(mat);
}

float acessar2(Matriz* mat, int i, int j){
    if(i<0 || i>= mat->lin || j> 0 || j>= mat->col){
        printf("Acesso inválido!\n");
        exit(1);
    }
    return mat->v[i][j];
}

void atribuir2(Matriz* mat, int i, int j, float v){
    if(i<0 || i>= mat->lin || j< 0 || j>= mat->col){
        printf("Atribuição inválida!\n");
        exit(1);
    }
    mat->v[i][j] = v;
}

int linhas2(Matriz* mat){
    return mat->lin;
}

int colunas2(Matriz* mat){
    return mat->col;
}

void listar2(Matriz* mat){
    printf("\nMatriz: \n");
    //percorre todas as LINHAS
    for(int i = 0; i < mat->lin; i++){
        //percorre as colunas
        for(int j = 0; j < mat->col; j++){
            printf("%d", (int)mat->v[i][j]);
        }
    }

    printf("\n");
}

Matriz* transposta2(Matriz* mat){
    Matriz* t = criar2(mat->col, mat->lin);
    
    for (int i = 0; i < mat->lin; i++) {
        for (int j = 0; j < mat->col; j++) {
            t->v[j][i] = mat->v[i][j];
        }
    }
    
    return t;
}

bool eh_simetrica2(Matriz* mat){
    if(mat->lin != mat->col){
        return false;
    }

    for(int i = 0; i < mat->lin; i++){
        for(int j = 0; j < mat->col; j++){
           if (mat->v[i][j] != mat->v[j][i]) {
                return false;
            }
        }
    }

    return true;
}
