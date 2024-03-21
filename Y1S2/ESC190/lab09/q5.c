#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct LL{
    node *head;
}LL;



int LL_length(LL list){
    int out = 0;
    if (list.head==NULL){
        return out;
    } else {
        out++; //NEWLY ADDED FROM MIDTERM TO CORRECT Q5A
        node *current = list.head;
        while (current->next!=NULL){
            current=current->next;
            out++;
        }
    }
    return out;
}

int cmp(const void *a, const void *b) {
    const node *an = *(const node **)a; //Midterm Original: node *an = a;
    const node *bn = *(const node **)b; //Midterm Original: node *bn = b;
    return (an->data) - (bn->data);
}

// I had thought question wanted the pointer to the median node.
int median(LL list){//Changed from: (node*)median(LL list){
    int length = LL_length(list);
    node **nodes = (node **)malloc(sizeof(node *)*length);
    nodes[0]=list.head;
    for (int i =1;i<length;i++){
        nodes[i]=nodes[i-1]->next;
    }
    qsort(nodes, length, sizeof(node*), cmp);
    return (nodes[((int)length/2)])->data;//Changed from: return nodes[((int)length/2)+1];
}


int main() {
    // TESTING
    LL list;
    list.head = NULL;
    node *current = NULL;
    int nums[5]={5,3,4,1,2};
    for (int i = 0; i < 5; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = nums[i];
        new_node->next = NULL;
        if (list.head == NULL) {
            list.head = new_node;
        } else {
            current = list.head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    printf("Linked List: ");
    node *current2 = list.head;
    while (current2 != NULL) {
        printf("%d ", current2->data);
        current2 = current2->next;
    }
    printf("\n");

    printf("Length of the linked list: %d\n", LL_length(list));
    printf("Median of the linked list: %d\n", median(list));

    return 0;
}
