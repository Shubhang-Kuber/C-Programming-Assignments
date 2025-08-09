#include<stdio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
    struct NODE *prev;
};

struct NODE *head=NULL;

void insertAtBeginning(int Data);
void traversal();
void insertAtEnd(int Data);

int main(){
    insertAtBeginning(5);
    insertAtBeginning(4);
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);

    traversal();

}

void insertAtBeginning(int Data){
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = Data;
    newNode->next = head;
    newNode->prev=NULL;

    if(head!=NULL){
        head->prev=newNode;
    }
    head=newNode;
}

void traversal(){
    
    struct NODE *temp = head;
    struct NODE *last = NULL;

    printf("Forward Traversal: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        last = temp; // store last node
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Backward Traversal: ");
    temp = last;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("HEAD\n");

}

void insertAtEnd(int Data){
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
    newNode->data = Data;
    newNode->next=NULL;
    
    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }

    struct NODE *temp = head;
    while(temp!=NULL && temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}