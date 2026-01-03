#include<stdio.h>
#include<stdlib.h>

#define MAX 20

typedef struct{
    int arr[20];
    int front,  rear;
    int size;
} Queue;

void enqueue(Queue *q, int data);
int isFull(Queue *q);
void dequeue(Queue *q);
int isEmpty(Queue *q);
void front(Queue *q);
void rear(Queue *q);

int main(){
    Queue q;
    q.size=0;
    q.front = -1;
    q.rear= MAX-1;

    printf("Enter the no of elements in the queue\n");
    int n;
    scanf("%d", &n);
    for(int i=0; i<=n; i++){
        enqueue(&q, i);
    }
    dequeue(&q);
    front(&q);
    rear(&q);
    

}
void enqueue(Queue *q, int data){
    if(isFull(q)){
        printf("Overflow Condition\n");
        return ;
    }
    q->rear = (q->rear+1)%MAX;
    q->arr[q->rear] = data;
    q->size = q->size+1;

}

int isFull(Queue *q){
    if(q->size==MAX-1){
        return 1;
    }
    else{
        return 0;
    }
}
void dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Underflow Condition\n");
        return;
    }
    int temp = q->arr[q->front];
    q->front = (q->front+1)%MAX;
    printf("The element deleted is %d \n", temp);
    q->size = q->size-1;
}

int isEmpty(Queue *q){
    if(q->size==-1){
        return 1;

    }
    else{
        return 0;
    }
}

void front(Queue *q){
    if(isEmpty(q)){
    printf("No element to delete\n");
    }
    printf("Element at the front is %d", q->arr[q->front]);
}

void rear(Queue *q){
    if(isFull(q)){
    printf("No element to Add\n");
    }
    printf("Element at the rear is %d", q->arr[q->rear]);
}

