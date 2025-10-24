#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr [5] = {1,2,3,4,5};
    int *ptr = &arr[0];

    ptr = ptr +3;
    printf("%i\n", *ptr);

    ptr = ptr -2;
    printf("%i\n", *ptr);
}