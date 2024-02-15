#include "intlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void create_list_from_data(IntList **p_IntList, int *data_arr, int size) {
    IntList *list = (IntList *)malloc(sizeof(IntList));
    list->data = (int *)malloc(size * sizeof(int));
    list->size = size;
    for (int i = 0; i < list->size; i++) {
        list->data[i] = data_arr[i];
    }
    list->capacity = size;
    *p_IntList = list;
}

void list_destroy(IntList *list) {
    free(list->data);
    free(list);
}

int list_get(IntList *list, int index) {
    return list->data[index];
}
