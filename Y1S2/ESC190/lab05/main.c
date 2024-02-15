// Compiling with terminal
// gcc -o main main.c intlist_helper.c intlist.c
// gcc -o main main.c intlist_helper.c intlist2.c
// ./main


#include <stdio.h>
#include "intlist.h"
#include "intlist_helper.c"
// #include "intlist.c"
#include "intlist2.c"

void print_list(IntList *list) {
    printf("List: ");
    for (int i = 0; i < list->size; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    // Test create_list_from_data
    printf("Creating list from data...\n");
    int data[] = {1, 2, 3, 4, 5};
    IntList *list;
    create_list_from_data(&list, data, 5);
    printf("Initial list: ");
    print_list(list);
    
    // Test list_append
    printf("\nAppending 6 to the list...\n");
    list_append(list, 6);
    printf("List after appending 6: ");
    print_list(list);
    
    // Test list_insert
    printf("\nInserting 0 at the beginning of the list...\n");
    list_insert(list, 0, 0); // Insert 0 at the beginning
    printf("List after inserting 0 at the beginning: ");
    print_list(list);
    
    printf("\nInserting 7 at the end of the list...\n");
    list_insert(list, 7, list->size); // Insert 7 at the end
    printf("List after inserting 7 at the end: ");
    print_list(list);
    
    printf("\nInserting 100 at index 3 of the list...\n");
    list_insert(list, 100, 3); // Insert 100 at index 3
    printf("List after inserting 100 at index 3: ");
    print_list(list);
    
    // Test list_delete
    printf("\nDeleting elements at index 0...\n");
    list_delete(list, 0);
    list_delete(list, 0);
    list_delete(list, 0);
    list_delete(list, 0);
    list_delete(list, 0);
    list_delete(list, 0);
    list_delete(list, 0);
    printf("List after deleting elements at index 0: ");
    print_list(list);
    
    // Test list_get
    printf("\nElement at index 1: %d\n", list_get(list, 1)); // Print element at index 1
    
    // Test list_destroy
    printf("\nDestroying the list...\n");
    list_destroy(list);
    printf("List destroyed\n");
    
    return 0;
}
