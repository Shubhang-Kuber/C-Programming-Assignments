#include <stdio.h>
#define SIZE 5

struct Stack {
    int arr[SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    if (s->top == SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct Stack *s) {
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->arr[++(s->top)] = value;
        printf("%d pushed into stack.\n", value);
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1;
    } else {
        return s->arr[(s->top)--];
    }
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Nothing to peek.\n");
        return -1;
    } else {
        return s->arr[s->top];
    }
}

void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= s->top; i++) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element is: %d\n", peek(&s));

    printf("%d popped from stack.\n", pop(&s));
    display(&s);

    return 0;
}
