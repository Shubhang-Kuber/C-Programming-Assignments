#include<stdio.h>
#include<stdlib.h>

int factorial(int n);

int main(){
    int n;
    printf("Enter the number\n");
    scanf("%i", &n);

    int k = factorial(n);
    printf("The factorial is %i", k);
    
}

int factorial (int n){
    int fact = 1;
    if(n==0 || n==1){
        return fact;
    }
    fact = n*factorial(n-1);
    return (fact);
}