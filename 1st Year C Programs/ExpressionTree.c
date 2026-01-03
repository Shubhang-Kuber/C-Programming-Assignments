#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 50

typedef struct Node{
    char data;
    struct Node *left;
    struct Node *right;
}Node;

int precedence(char ch);
void infixToPostfix(char infix[], char postfix[]);
Node * createNode(char data);
Node * createExpressionTree(char postfix[]);
 void inorder(Node *root);


int main(){
    char infix[MAX], postfix[MAX];
    printf("Enter the infix expression without spaces\n");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("The postfix expresion is: %s", postfix);
    Node *root = createExpressionTree(postfix);
    printf("The inorder traversal of Expression tree is:\n");
    inorder(root);


}
int precedence(char ch){
    switch(ch){
        case '^': return 3;
        case '/': 
        case '*': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]){
    char Stack[MAX];
    int top=-1;
    int k=0;
    for(int i=0; infix[i]!='\0'; i++){
        char ch = infix[i];
        if(isalnum(ch)){
            postfix[k++]=ch;
        }
        else if(ch == '('){
            Stack[++top]=ch;
        }
        else if(ch == ')'){
            while(top!=-1 && Stack[top]!='('){
                postfix[k++]=Stack[top--];
            }
            top--;
        }
        else{
            while(top!=-1 && precedence(Stack[top])>= precedence(ch)){
                postfix[k++] = Stack[top--];
            }
            Stack[++top] = ch;
        }
    }
    while(top!=-1){
        postfix[k++] = Stack[top--];
    }
    postfix[k] = '\0';
}

Node * createNode(char data){
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node * createExpressionTree(char postfix[]){
    Node *Stack[MAX];
        int top=-1;
        for(int i=0; postfix[i]!='\0'; i++){
            char ch = postfix[i];
            if(isalnum(ch)){
                Stack[++top] = createNode(ch);
            }
            else{
                
                Node * right = Stack[top--];
                Node *left = Stack[top--];
                Node *newNode = createNode(ch);
                newNode->left = left;
                newNode->right = right;
                Stack[top++] = newNode;
            }
        }
        return Stack[top];
}
 void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
 }