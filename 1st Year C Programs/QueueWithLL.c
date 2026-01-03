#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int data;
    struct Node *next;
}Node;
Node *front = NULL;
Node *rear = NULL;


void enqueue(int val);
void display();
int dequeue();
void peek();

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("Diaplaying the elemnts of the queue\n");
    display();
    printf("Dequeuing the fron element\n");
    dequeue();
    printf("Displaying the front elemnt %d", peek());
}

void enqueue(int val){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    if(rear == NULL){
        front=rear=newNode;
        return;
    }
    rear->next = newNode;
    rear=newNode;
    newNode->next = front;
}
void display(){
    if(front==NULL){
        printf("The Queue is Empty\n");
        return;
    }
    Node *temp = front;
    while(temp!=NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int dequeue(){
    if(front==NULL){
        printf("No Elements to delete\n");
        return;
    }
    if(front==rear){
        int temp = rear->data;
        printf("The data deleted is\n", temp);
        free(rear);
    }
    Node *curr = front;
    int value = curr->data;
    free(curr);
    return value;
}

void peek(){
    if(front==NULL){
        printf("There is no elemnt in the queue\n");
        return;
    }
    printf("The element in the front is %d", front->data);

}
