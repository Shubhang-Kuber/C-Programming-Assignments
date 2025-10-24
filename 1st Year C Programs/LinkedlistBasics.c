#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{
    int data;
    struct NODE *next;
};

void insertBeginning(int data);
void insertAtEnd(int data);
void traverseList();
void countNoOfNodes();

struct NODE *head=NULL;

int main(){
    printf("Production of a linked list\n");

    for(int i=5; i>=1; i--){
        insertBeginning(i);
    }

    for(int i=6; i<=10; i++){
        insertAtEnd(i);
    }
    traverseList();
    countNoOfNodes();

    return 0;
}

void insertBeginning(int data){
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data = data;
    newNode->next=head;
    head=newNode;
}

void insertAtEnd(int data){
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data=data;
    newNode->next=NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
    
    struct NODE *temp;
    temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    temp->next=newNode;
}

void traverseList(){
    struct NODE *temp = head;
    printf("\nhead->");

    while(temp!=NULL){
        printf("%i->", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

void countNoOfNodes(){
    int count=0;
    struct NODE *temp = head;
    

    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("The no of Nodes is %i\n", count);

}
