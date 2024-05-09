#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int getElem(matrix *M, int i, int j){
    return M->values[i*M->n+j];
}
void setElem(matrix *M, int value, int i, int j){
    M->values[i*M->n+j]=value;
}
matrix *addMatrix(matrix *A, matrix *B){
    matrix *C = (matrix *)malloc(sizeof(matrix));
    C->m = A->m;
    C->n = A->n;
    C->values = (int *)malloc(sizeof(int)*C->m*C->n);
    for (int i = 0; i<C->m;i++){
        for (int j = 0; j<C->n;j++){
            int num = getElem(A, i,j)+getElem(B, i,j);
            setElem(C, num, i, j);
        }
    }
    return C;
}
void printMatrix(matrix *M){
    for (int i = 0; i<M->m;i++){
        for (int j = 0; j<M->n;j++){
            printf("%d ", getElem(M, i,j));
        }
        printf("\n");
    }
}