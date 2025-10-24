#include<stdio.h>
#include<stdlib.h>
#include<String.h>

int main(){
    char str[50]="Kuber";

    char strdest[10];
    int len = strlen(str)-1;
    int i=0;

    while(str[i]!='\0'){
        strdest[i]=str[len];
        len--;
        i++;
    }

    printf("New string is %s", strdest);
}
