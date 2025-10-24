#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    int n;
    printf("Enter the number\n");
    scanf("%i", &n);

    double sum = 0.0;
    
    for(int i=1; i<=n; ++i){
        printf("1/%i", i);
        sum = sum + 1.0/i;
        if (i < n) printf("+ ");
    }

    printf("The sum is %i", sum);
}