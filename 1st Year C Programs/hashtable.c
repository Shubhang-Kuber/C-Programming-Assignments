#include<stdio.h>
#include<stdlib.h>

#define SIZE 11
#define EMPTY -1
#define DELETED -2


int hash1(int key);
int hash2(int key);
void insert(int hashTable[], int key);
void deleted(int hashTable[], int key);
void display(int hashTable[]);

int main(){
    int hashTable[SIZE];
    for(int i=0; i<SIZE; i++){
        hashTable[i] = EMPTY;

    }
    insert(hashTable, 10);
    insert(hashTable, 20);
    insert(hashTable, 30);
    insert(hashTable, 40);
    insert(hashTable, 50);

    display(hashTable);
    printf("Enter the key to be deleted\n");
    int key;
    scanf("%d", &key);
    deleted(hashTable, key);
    display(hashTable);



}

int hash1(int key){
    return key%SIZE;
}

int hash2(int key){
    return 1+(key%(SIZE-1));
}


void insert(int hashTable[], int key){
    int index = hash1(key);
    int step = hash2(key);
    for(int i=0; i<SIZE; i++){
        int newIndex = (index+i*step)%SIZE;
        if(hashTable[newIndex]==EMPTY || hashTable[newIndex]==DELETED){
            hashTable[newIndex] = key; 
            printf("The %d has been inserted at %d", key, newIndex);
            return;
        }


    }
    printf("Cannot insert %d into the table", key);
}

void deleted(int hashTable[], int key){
    int index = hash1(key);
    int step = hash2(key);
    for(int i=0; i<SIZE; i++){
        int newIndex = (index + i*step)%SIZE;
        if(hashTable[newIndex]==key){
            hashTable[newIndex] = DELETED;
            return;
        }
        if(hashTable[newIndex] == EMPTY){
            break;
            
        }

    }
    printf("Element not found\n");
}

void display(int hashTable[]){
    printf("Displaying the lements of the table\n");
    for(int i=0; i<SIZE; i++){
        if(hashTable[i]==EMPTY){
            printf("%d", EMPTY);
        }
        if(hashTable[i]==DELETED){
            printf("%d", DELETED);
        }
        else{
            printf("%d", hashTable[i]);
        }
    }
}
