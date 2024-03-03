#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void LL_append(LL *my_list, int new_elem){
    // Next field of last node is NULL
    node *new_pointer=(node *)malloc(sizeof(node));
    new_pointer->next=NULL;
    new_pointer->data=new_elem;
    
    if (my_list->head==NULL){
        my_list->head=new_pointer;
    }else {
        node *pointer_search=my_list->head;
        while (pointer_search->next!=NULL){
            pointer_search=pointer_search->next;
        }
        pointer_search->next=new_pointer;
    }
    my_list->size++;
    LL_print(my_list);
}

int validate_list_length(LL *my_list){
    int size_count = 0;
    if (my_list->head!=NULL){
        node *pointer_search = my_list->head;
        size_count++;
        while (pointer_search->next != NULL){
            pointer_search=pointer_search->next;
            size_count++;
        }
    }
    if (my_list->size==size_count){
        return 1;
    } else {
        return 0;
    }
}
void LL_delete(LL *my_list, int index){
    node *current=my_list->head;
    node *past = NULL;
    for (int i =0;i<index;i++){
        past = current;
        current=current->next;
    }
    past->next = current->next;
    free(current);
    current=NULL;
    my_list->size--;
    LL_print(my_list);
}

void LL_print(LL *my_list) {
    node *current = my_list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void LL_swap(LL *my_list, int index1, int index2){
    node *node1 = my_list->head;
    for (int i =1;i<=index1;i++){
        node1 = node1->next;
    }
    int value1 = node1->data;
    node *node2 = my_list->head;
    for (int i =1;i<=index2;i++){
        node2 = node2->next;
    }
    int value2=node2->data;

    node1->data=value2;
    node2->data=value1;
    // LL_print(my_list);
}

void LL_reverse(LL *my_list){
    for (int i =0;i<(int)(my_list->size/2);i++){
        LL_swap(my_list, i, my_list->size-i-1);
    }
    LL_print(my_list);
}
