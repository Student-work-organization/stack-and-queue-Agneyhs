#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void init(struct Stack* s) {
    s->top = NULL;
}

int empty(struct Stack* s) {
    return (s->top == NULL);
}

void push(struct Stack* s, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;

    printf("%d pushed to stack\n", data);
}

int pop(struct Stack* s) {
    if (empty(s)) {
        printf("Stack Underflow\n");
        return -1;  // acts like None
    }

    struct Node* temp = s->top;
    int popped = temp->data;

    s->top = temp->next;
    free(temp);

    return popped;
}

int peek(struct Stack* s) {
    if (empty(s)) {
        printf("Stack is empty\n");
        return -1;
    }

    return s->top->data;
}

int main() {
    struct Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    printf("Is stack empty? %s\n", empty(&s) ? "Yes" : "No");

    return 0;
}