#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *createNode(int val);
Node *insertTree(Node *root, int val);
void inorder(Node *root);
int countNoOfNodes(Node *root);
int countNoOfLeafNodes(Node *root);

int main(){
    Node *root = NULL;
    int n;
    printf("Enter the no of elemnts in the tree\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        root=insertTree(root, i);
    }
    inorder(root);
    printf("The no of nodes in the tree are : %d\n", countNoOfNodes(root));
    printf("The no of leaf nodes in the tree are : %d\n", countNoOfLeafNodes(root));

}

Node *createNode(int val){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertTree(Node *root, int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->data){
        root->left = insertTree(root->left, val);
    }
    else{
        root->right = insertTree(root->right, val);
    }
    return root;
}

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\n", root->data);
        inorder(root->right);
    }
}

int countNoOfNodes(Node *root){
    if(root==NULL){
        return 0;
    }
    
    return 1+countNoOfNodes(root->left) + countNoOfNodes(root->right);
    
}

int countNoOfLeafNodes(Node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
     return countNoOfLeafNodes(root->left)+countNoOfLeafNodes(root->right);
}