#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct CircularQueue{
    int size;
    int *data;
    int start;
    int end;
}CircularQueue;

void initialize(CircularQueue *q, int size) {
    q->data = (int *)malloc(size * sizeof(int));
    for (int i =0;i<size;i++){
        q->data[i]=0;
    }
    q->size = size;
    q->start = size/2-1;
    q->end = size/2-1;
}

void enqueue(CircularQueue *q, int item) {
    q->end = (q->end + 1) % q->size;
    if (q->data[q->end]!=0){
        q->data = (int *)realloc(q->data, (q->size+1) * sizeof(int));
        memmove(q->data+q->start+1, q->data+q->start, sizeof(int)*(q->size-q->start));
        q->size++;
        if (q->start>q->end){
            q->start++;
        }
    }
    q->data[q->end] = item;
}

void dequeue(CircularQueue *q) {
    q->start = (q->start + 1) % q->size;
    q->data[q->start] = 0;
}

void print(CircularQueue *q){
    for (int i = 0;i<q->size;i++){
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

void destroyQueue(CircularQueue *q) {
    free(q->data);
    free(q);
}


int main() {
    CircularQueue q;
    initialize(&q, 5);
    enqueue(&q, 1);
    print(&q);
    enqueue(&q, 1);
    print(&q);
    enqueue(&q, 1);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    enqueue(&q, 1);
    print(&q);
    enqueue(&q, 1);
    print(&q);
    enqueue(&q, 1);
    print(&q);
    enqueue(&q, 1);
    print(&q);
    enqueue(&q, 1);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    dequeue(&q);
    print(&q);
    return 0;
}