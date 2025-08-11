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
void deleteAtBeginning();
void deleteAtEnd();

int main(){
    insertAtBeginning(5);
    insertAtBeginning(4);
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);

    traversal();

    insertAtEnd(6);
    insertAtEnd(7);
    insertAtEnd(8);
    insertAtEnd(9);

    traversal();

    deleteAtBeginning();
    deleteAtEnd();

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
    
    while (last != NULL) {
        printf("%d->", last->data);
        last = last->prev;
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

void deleteAtBeginning(){
    struct NODE *temp;

    if(head==NULL){
        return;
    }

    if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void deleteAtEnd(){
    if (head == NULL) {
        // Empty list
        return;
    }

    if (head->next == NULL) {        
        free(head);
        head = NULL;
        return;
    }

    
    struct NODE *last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->prev->next = NULL;
    free(last);
}


