#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    char ch;
    printf("Enter the character\n");
    scanf("%c", &ch);

    ch = tolower(ch);

    switch(ch){
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        printf("The character is a vowel");
        break;

        default:
        if((ch>='a')&&(ch<='z')){
            printf("Th character is a consonant\n");
        }
        else{
            printf("Not a character");
        }
    }
}