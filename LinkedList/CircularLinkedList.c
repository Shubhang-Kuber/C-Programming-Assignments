#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct NODE{
    int data;
    struct NODE *next;
};

struct NODE *head=NULL;

void traversal();
void insertAtBeginning(int Data);
void insertAtEnd(int data);

int main(){

}

void traversal(){
    if(head==NULL){
        return;
    }

    struct NODE *temp=head;
    do{
        printf("%d->", temp->data);
        temp=temp->next;
    }while(temp!=head);
}

void insertAtBeginning(int Data){
    struct NODE *newNode = (struct NODE*)malloc(sizeof(struct NODE));
    newNode->data=Data;
    if(head==NULL){
        newNode->next=newNode;
        newNode=head;
        return;
    }

    struct NODE *temp=head;

    while(temp->next!=head){
        temp=temp->next;
    }
    newNode->next=head;
    temp->next=newNode;
    head=newNode;
}

void insertAtEnd(int data){
    struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
    newNode->data=data;

    if(head==NULL){
        newNode->next=newNode;
        head=newNode;
        return;
    }

    newNode->next=head;
    struct NODE *temp = head;

    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
}