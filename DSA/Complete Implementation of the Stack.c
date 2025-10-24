/* This program includes the complete implementation of a Stack */
/* Operations: Push, Pop, Peek, isFull, isEmpty */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>   // for INT_MIN

struct STACK {
    int top;
    unsigned capacity;
    int *array;
};

// Function declarations
struct STACK *createStack(unsigned capacity);
int isFull(struct STACK *newStack);
int isEmpty(struct STACK *newStack);
void pushItem(struct STACK *newStack, int item);
int popItem(struct STACK *newStack);
int peek(struct STACK *newStack);

int main() {
    struct STACK *stack = createStack(5);

    pushItem(stack, 10);
    pushItem(stack, 20);
    pushItem(stack, 30);

    printf("\nTop element is %d\n", peek(stack));

    printf("%d popped from stack\n", popItem(stack));
    printf("%d popped from stack\n", popItem(stack));

    if (isEmpty(stack))
        printf("Stack is empty\n");
    else
        printf("Stack is not empty\n");

    return 0;
}

// Function to create a stack of given capacity
struct STACK *createStack(unsigned capacity) {
    struct STACK *newStack = (struct STACK *)malloc(sizeof(struct STACK));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->array = (int *)malloc(newStack->capacity * sizeof(int));
    return newStack;
}

// Check if the stack is full
int isFull(struct STACK *newStack) {
    return newStack->top == newStack->capacity - 1;
}

// Check if the stack is empty
int isEmpty(struct STACK *newStack) {
    return newStack->top == -1;
}

// Push an item onto the stack
void pushItem(struct STACK *newStack, int item) {
    if (isFull(newStack)) {
        printf("Stack overflow! Cannot push %d\n", item);
        return;
    }
    newStack->array[++(newStack->top)] = item;
    printf("%d pushed into stack\n", item);
}

// Pop an item from the stack
int popItem(struct STACK *newStack) {
    if (isEmpty(newStack)) {
        printf("Stack underflow! Nothing to pop.\n");
        return INT_MIN;
    }
    return newStack->array[(newStack->top)--];
}

// Peek at the top element without removing it
int peek(struct STACK *newStack) {
    if (isEmpty(newStack)) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return newStack->array[newStack->top];
}
