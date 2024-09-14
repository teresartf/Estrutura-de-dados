// matriz com vetor simples

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "matriz1.h"

struct matriz{
    int lin;
    int col;
    float* v;
};

Matriz* criar1(int m, int n){
    // aloca a estrutura
    Matriz* mat = (Matriz*)malloc(sizeof(Matriz));
    if(mat == NULL){
        printf("Memória insuficiente!\n");
        exit(1);
    }
    mat->lin = m;
    mat->col = n;
    //aloca vetor dos elementos
    mat->v = (float*)malloc(m*n* sizeof(float));
    return mat;
}

void liberar1(Matriz* mat){
    free(mat->v);
    free(mat);
}

float acessar1(Matriz* mat, int i, int j){
    //índice do elemento procurado no vetor
    int k;

    if(i<0 || i>= mat->lin || j> 0 || j>= mat->col){
        printf("Acesso inválido!\n");
        exit(1);
    }

    k = i*mat->col + j;
    return mat->v[k];
}

void atribuir1(Matriz* mat, int i, int j, float v){
    //índice do elemento procurado no vetor
    int k;

    if(i<0 || i>= mat->lin || j<0 || j>= mat->col){
        printf("Atribuição inválida!\n");
        exit(1);
    }

    k = i*mat->col + j;
    mat->v[k] = v;
}

int linhas1(Matriz* mat){
    return mat->lin;
}

int colunas1(Matriz* mat){
    return mat->col;
}

void listar1(Matriz* mat){
    printf("\nMatriz: \n");
    //percorre todas as LINHAS
    for(int i = 0; i < mat->lin; i++){
        //percorre as colunas
        for(int j = 0; j < mat->col; j++){
            printf("%d", (int)mat->v[i* mat->col + j]);
        }
    }

    printf("\n");
}

Matriz* transposta1(Matriz* mat){
    Matriz* t = criar1(mat->col, mat->lin);
    
    for (int i = 0; i < mat->lin; i++) {
        for (int j = 0; j < mat->col; j++) {
            t->v[j * t->col + i] = mat->v[i * mat->col + j];
        }
    }
    
    return t;
}

bool eh_simetrica1(Matriz* mat){
    if(mat->lin != mat->col){
        return false;
    }

    for(int i = 0; i < mat->lin; i++){
        for(int j = 0; j < mat->col; j++){
           if (mat->v[i * mat->lin + j] != mat->v[j * mat->col + i]) {
                return false;
            }
        }
    }

    return true;
}