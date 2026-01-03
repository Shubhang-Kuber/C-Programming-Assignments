#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 50

typedef struct{
    char data[50];
    int top;
} Stack;
void init( Stack *s);
void infixToPostfix(char infix[]);
void push (Stack *s, char ch);
char pop (Stack *s);
int precedence(char ch);
char peek (Stack *s);

int main(){
    char infix[MAX];
    printf("Enter the infix expression wihtout spaces\n");
    scanf("%s", infix);
    infixToPostfix(infix);
}
void init( Stack *s){
    s->top = -1;
}
void infixToPostfix(char infix[]){
    Stack s;
    init(&s);
    char postfix[50];
    int i=0, j=0;
    char ch, temp;
    printf("Converting infix to postfix\n");
    while(ch=infix[i++]!='\0'){
        if(isalnum(ch)){
            postfix[j++] = ch;
        }
        else if(ch=='('){
            push(&s, ch);
        }
        else if(ch==')'){
            while((temp=pop(&s))!='\0'){
                postfix[j++] = ch;
            }
        }
        else{
            if(precedence(peek(&s))>=precedence(ch)){
                postfix[j++]=pop(&s);
                push(&s, ch);
            }
        }
        

    }
    while(s->top!=-1){
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
    printf("The postfix expression is : %s", postfix);

    
}

void push (Stack *s, char ch){
    if(s->top == MAX-1){
        printf("Overflow condition\n");
    }
    s->data[++(s->top)]=ch;
}

char pop (Stack *s){
    if(s->top==-1){
        printf("Underflow condition\n");
    }
    return s->data[(s->top)--];
}
int precedence(char ch){
    switch(ch){
        case '^': return 3;
        case '/':
        case '*': return 2;
        case '+':
        case '-': return 1;
        deafult: return 0;

    }
}

char peek (Stack *s){
    if(s->top==-1){
        printf("Underflow condition\n");
        return '\0';

    }
    return s->data[s->top];
}
