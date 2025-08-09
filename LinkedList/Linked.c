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

int main(){

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
    struct NODE *temp=head;
    while(temp!=NULL && temp->next!=NULL){
        printf("%i->", temp->data);
        temp=temp->next;
    }
    printf("\n");
}