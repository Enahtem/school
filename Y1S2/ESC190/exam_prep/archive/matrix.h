#if !defined(thing)
#define thing

typedef struct matrix{
    int m;
    int n;
    int *values;
} matrix;

int getElem(matrix *M, int i, int j);
void setElem(matrix *M, int value, int i, int j);
matrix *addMatrix(matrix *A, matrix *B);
void printMatrix(matrix *M);

#endif