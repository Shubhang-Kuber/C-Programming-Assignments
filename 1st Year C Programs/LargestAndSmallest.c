#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the size of th array\n");
    scanf("%i", &n);

    int arr[n];

    printf("Enter the array elements\n");
    for(int i=0; i<n; i++){
        scanf("%i", &arr[i]);
    }

    int largestElement = arr[0];
    int smallestElement = arr[0];

    for(int i=0; i<n; i++){
        if(arr[i]>largestElement){
            largestElement = i;
        }
        else if(arr[i]<smallestElement){
            smallestElement=i;
        }
        }
    printf("The largest Element is %i i position %i", arr[largestElement], largestElement);
    printf("The smallest Element is %i i position %i", arr[smallestElement], smallestElement);
}