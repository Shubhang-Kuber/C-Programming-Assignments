#include<stdio.h>
#include<stdli.h>


int main(){
    int a,b,c;
    printf("Enter the three intger values");
    scanf("%i%i%i", &a, &b, &c);

    if(a>b){
        if(a>c){
            printf("The greatest is %i", a);
        }
        else{
            printf("The greatest id %i", c);
        }
    }
    else{
        if(b>c){
            printf("The greatest is %i", b);
        }
        else{
            printf("The greatest id %i", c);
        }
    }
}