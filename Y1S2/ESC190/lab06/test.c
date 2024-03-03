#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}node;

typedef struct pyinteger{
    node *head;
}pyinteger;

void plusplus(pyinteger *n){
    if ((n->head->value)==9){
        node *current = n->head;
        while (current->value==9){
            current->value=0;
        }
        current->next->value++;
    } else {
        n->head->value++;
    }
}


void print_pyinteger(pyinteger *n) {
    node *current = n->head;
    while (current != NULL) {
        printf("%d", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(){

    return 0;
}