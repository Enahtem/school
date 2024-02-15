#include "intlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_append(IntList *list, int new_elem) {
    printf("intlist\n");
    list->size += 1;
    if (list->capacity < list->size) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size - 1] = new_elem;
}

void list_insert(IntList *list, int new_elem, int index) {
    printf("intlist\n");
    list->size += 1;
    if (list->capacity < list->size) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
    memmove(&(list->data[index + 1]), &(list->data[index]), (list->size - index - 1) * sizeof(int));
    list->data[index] = new_elem;
}

void list_delete(IntList *list, int index) {
    printf("intlist\n");
    list->size -= 1;
    memmove(&(list->data[index]), &(list->data[index + 1]), (list->size - index) * sizeof(int));
}
