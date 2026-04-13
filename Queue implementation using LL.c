#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

void init(struct Queue* q) {
    q->front = q->rear = NULL;
}

int is_empty(struct Queue* q) {
    return (q->front == NULL);
}

void enqueue(struct Queue* q, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int front(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return -1; // acts like None
    }
    return q->front->data;
}

int main() {
    struct Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("Front element: %d\n", front(&q));
    printf("Is queue empty? %s\n", is_empty(&q) ? "Yes" : "No");

    return 0;
}