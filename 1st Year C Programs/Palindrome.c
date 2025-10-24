#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isPalindrome( char *str, int start, int end);

int main(){
    char str[30];
    printf("Enter the string\n");
    scanf("%s", str);

    int len = strlen(str);
    int start=0;
    int end = len-1;

    int k = isPalindrome(str, start, end);

    if(k){
        printf("The String is a palindrome\n");
    }
    else{
        printf("the string is not a palindrome\n");
    }
}

int isPalindrome( char *str, int start, int end){
    if(start>=end){
        return 1;
    }

    if(str[start]!=str[end]){
        return 0;
    }
    return isPalindrome(str, start+1, end-1);
}