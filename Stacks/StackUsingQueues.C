/*
Push operation to implement LIFO with two queues algorithm
1. Push x to q2
2. Move q1 to q2 one by one
3. Swap q1 and q2

Pop operation to implement LIFO with two queues algorithm
1. Remove from the front of q1
*/

#include <stdio.h>
#define SIZE 100

struct Queue {
    int arr[SIZE];
    int front, rear;
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int isEmpty(struct Queue *q) {
    return q->front == q->rear;
}

int isFull(struct Queue *q) {
    return q->rear == SIZE;
}

void enqueue(struct Queue *q, int x) {
    if (!isFull(q)) {
        q->arr[q->rear++] = x;
    }
}

int dequeue(struct Queue *q) {
    if (!isEmpty(q)) {
        return q->arr[q->front++];
    }
    return -1;
}

int front(struct Queue *q) {
    if (!isEmpty(q)) {
        return q->arr[q->front];
    }
    return -1;
}

struct Stack {
    struct Queue q1, q2;
};

void initStack(struct Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(struct Stack *s, int x) {
    enqueue(&s->q2, x);
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }
    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(struct Stack *s) {
    if (isEmpty(&s->q1)) return -1;
    return dequeue(&s->q1);
}

int peek(struct Stack *s) {
    if (isEmpty(&s->q1)) return -1;
    return front(&s->q1);
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Top element: %d\n", peek(&s));

    return 0;
}
