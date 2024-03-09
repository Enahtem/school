#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->data = (int *)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
}

int isEmpty(Queue *q) {
    return q->size == 0;
}

int isFull(Queue *q) {
    return q->size == q->capacity;
}

// void enqueue(Queue *q, int item) {
//     if (isFull(q)) {
//         printf("Queue is full\n");
//         return;
//     }
//     q->rear = (q->rear + 1) % q->capacity;
//     q->data[q->rear] = item;
//     q->size++;
// }


void enqueue(Queue *q, int item) {
    if (isFull(q)) {
        // Resize the queue
        int newCapacity = q->capacity * 2;
        int *newData = (int *)malloc(newCapacity * sizeof(int));
        int i, j;
        j = 0;
        for (i = q->front; i != q->rear; i = (i + 1) % q->capacity) {
            newData[j++] = q->data[i];
        }
        newData[j] = q->data[i]; // Copy the last element
        free(q->data); // Free the old data
        q->data = newData; // Update the data pointer
        q->front = 0;
        q->rear = q->size - 1;
        q->capacity = newCapacity; // Update the capacity
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size++;
}


int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->data[i]);
        i = (i + 1) % q->capacity;
    }
    printf("%d\n", q->data[i]);
}

void destroyQueue(Queue *q) {
    free(q->data);
}

int main() {
    Queue q;
    initQueue(&q, 5);

    printf("Enqueue 1\n");
    enqueue(&q, 1);
    printf("Enqueue 2\n");
    enqueue(&q, 2);
    printf("Enqueue 3\n");
    enqueue(&q, 3);
    printf("Enqueue 4\n");
    enqueue(&q, 4);
    printf("Enqueue 5\n");
    enqueue(&q, 5);
    printf("Queue: ");
    display(&q);

    printf("Dequeue: %d\n", dequeue(&q));
    printf("Dequeue: %d\n", dequeue(&q));

    printf("Enqueue 6\n");
    enqueue(&q, 6);
    printf("Enqueue 7\n");
    enqueue(&q, 7);
    printf("Queue: ");
    display(&q);

    printf("Enqueue 8\n");
    enqueue(&q, 8);
    printf("Queue: ");
    display(&q);

    destroyQueue(&q);
    return 0;
}