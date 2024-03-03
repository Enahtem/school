#include "linkedlist.h"
#include <stdio.h>

// gcc -o test_linkedlist test_linkedlist.c linkedlist.c ; ./test_linkedlist

int main(){
    LL my_list;
    my_list.head=NULL;
    my_list.size=0;
    LL_print(&my_list);
    LL_append(&my_list, 1);
    LL_append(&my_list, 2);
    LL_append(&my_list, 4);
    LL_append(&my_list, 7);
    LL_append(&my_list, 2);
    LL_append(&my_list, 8);
    LL_append(&my_list, 12);
    LL_delete(&my_list, 1);
    LL_reverse(&my_list);

    return 0;
}