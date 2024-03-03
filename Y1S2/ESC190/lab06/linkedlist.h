#ifndef NAME
#define NAME

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct LL{
    node *head;
    int size;
}LL;

void LL_append(LL *my_list, int new_elem);
int validate_list_length(LL *my_list);
void LL_delete(LL *my_list, int index);
void LL_print(LL *my_list);
void LL_swap(LL *my_list, int index1, int index2);
void LL_reverse(LL *my_list);

#endif