#include<stdio.h>
#include<stdlib.h>

struct QUEUE{
    int front, rear;
    unsigned capacity;
    int *arr;
};

void initialize(struct QUEUE *q, int capacity);
void enqueue(struct QUEUE *q, int item);
int dequeue(struct QUEUE *q);
int isFull(struct QUEUE *q);
int isEmpty(struct QUEUE *q);
void display(struct QUEUE *q);

int main(){
    struct QUEUE q;
    initialize(&q);

    enqueue(&q, 5);
    dequeue(&q);
    isEmpty(&q);
    isFull(&q);
    display(&q);
}

void initialize(struct QUEUE *q, int capacity){
    q->front=-1;
    q->rear=-1;
    q->capacity = capacity;
    q->arr = (struct QUEUE *)malloc(q->capacity *sizeof(int));
}

void enqueue(struct QUEUE *q, int item){
    if(isFull(q)){
        printf("Cannot insert element\n");
        return;
    }
    if(q->front==-1){
        q->front = q->front+1;
    }
    
    q->rear = q->rear + 1;
    q->arr[q->rear] = item;
    printf("Successfully added the %d \n", item);
}

int dequeue(struct QUEUE *q){
    if(isEmpty(q)){
        printf("Cannot delete element\n");
        return;
    }
    int x = q->arr[q->front];
    printf("%d has been deleted\n", x);
    q->front+=1;
    if(q->front > q->rear){
        q->front = -1;
    }
    return x;
}

int isFull(struct QUEUE *q){
    if(q->rear==q->capacity-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct QUEUE *q){
    if((q->front>q->rear)||(q->front==-1)){
        return 1;
    }
    else{
        return 0;
    }
}

void display(struct QUEUE *q){
    if(isEmpty(q)){
        printf("Cannot traverse the queue\n");
        return;
    }
    for(int i= q->front; i<=q->rear; i++){
        printf("%d\n", q->arr[i]);

    }
    printf("\n")
}
