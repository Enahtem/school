#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"

double fact(int n){
    if (n==0){
        return 1;
    } else {
        return n*fact(n-1);
    }
}

void replace_ws(char *s){
    char *find = "winter";
    char *replace = "summer";

    for (int i=0;i<strlen(s)-strlen(find)+1;i++){
        if (strncmp(s+i, find, strlen(find))==0){
            strncpy(s+i, replace, strlen(replace));
        }
    }
}

int same_list(int *arr1, int *arr2, int size1, int size2){
    if (size1 == 0 && size2 == 0){
        return 1;
    } else if (size1 == 0 && size2 == 0){
        return 0;
    }else if (arr1[0] == arr2[0]){
        return same_list(arr1+1, arr2+1, size1-1, size2-1);
    }else {
        return 0;
    }
}

typedef struct node{
int data;
struct node *next;
} node;

typedef struct LL{
node *head;
int size;
} LL;


void LL_append(LL *my_list, int new_val, int i){
    // Assume index is given that is valid within the linked list
    my_list->size+=1;
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = new_val;
    new_node->next = NULL;
    if (i == 0){
        new_node->next = my_list->head;
        my_list->head = new_node;
    } else {
        node *current = my_list->head;
        for (int j = 1;j<i;j++){
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void LL_print(LL *my_list){
    // Assume list has a head
    node *current = my_list->head;
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


char *dec2bin(const char *decimal){
    int value = atoi(decimal);
    char *out = (char *)malloc(sizeof(char));
    out[0] = '\0';
    while (value>0){
        out = (char *)realloc(out, (strlen(out)+2)*sizeof(char));
        if (value%2==1){
            value -=1;
            memmove(out+1, out, (strlen(out)+1)*sizeof(char));
            strncpy(out, "1", sizeof(char));
        } else {
            memmove(out+1, out, (strlen(out)+1)*sizeof(char));
            strncpy(out, "0", sizeof(char));
        }
        value=value/2;
    }
    return out;
}

int main(){
    //QUESTION 1
    printf("%.0f\n", fact(10));
    //Runtime Complexity: O(n)

    //QUESTION 2
    char s[] = "In the winter, I will rest and enjoy the sun. Winter is great! Wait, actually I mean winter.";
    replace_ws(s);
    printf("New String: %s\n", s);

    // QUESTION 3
    int arr1[] = {7, 8, 9};
    int arr2[] = {7, 8, 9};
    int arr3[] = {7, 8};
    int size1 = sizeof(arr1)/sizeof(int);
    int size2 = sizeof(arr2)/sizeof(int);
    int size3 = sizeof(arr3)/sizeof(int);
    printf("%d\t%d\n", same_list(arr1, arr2, size1, size2), same_list(arr2, arr3, size2, size3));

    // QUESTIoN 4
    LL *my_list = (LL *)malloc(sizeof(LL));
    my_list->size = 0;
    my_list->head = NULL;
    LL_append(my_list, 1, 0);
    LL_append(my_list, 2, 1);
    LL_append(my_list, 3, 0);
    LL_append(my_list, 4, 0);
    LL_append(my_list, 5, 0);
    LL_append(my_list, 6, 0);
    LL_print(my_list);


    // Question 5
    matrix *A = (matrix *)malloc(sizeof(matrix));
    matrix *B = (matrix *)malloc(sizeof(matrix));
    A->m = 2;
    A->n = 2;
    B->m = 2;
    B->n = 2;
    A->values = (int *)malloc(sizeof(int)*A->m*A->n);
    B->values = (int *)malloc(sizeof(int)*B->m*B->n);
    setElem(A, 1, 0,0);
    setElem(A, -1, 0,1);
    setElem(A, 2, 1,0);
    setElem(A, 0, 1,1);
    setElem(B, -1, 0,0);
    setElem(B, 2, 0,1);
    setElem(B, 0, 1,0);
    setElem(B, 1, 1,1);
    matrix *C = addMatrix(A,B);
    printMatrix(C);

    // Question 8
    printf("%s", dec2bin("100"));


    return 0;
}