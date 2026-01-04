#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    /* data */
}Node;

Node* minValueNode(Node* node);
Node *createNode(int val);
Node *createBST(Node *root, int val);
void inorder(Node *root);
Node *deleteNode(Node *root, int val);


int main(){
    Node *root=NULL;
    int n;
    printf("Enter the no of elments in the BST\n");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        root=createBST(root,i);
    }
    printf("Inorder traversal of the tree is\n");
    inorder(root);
    int del;
    printf("Enter the element to delete\n");
    scanf("%d", &del);
    root = deleteNode(root, del);

    printf("The tree after the deletion is\n");
    inorder(root);

}

Node *createNode(int val){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *createBST(Node *root, int val){
    if(root==NULL){
        return createNode(val);
    }
    if(val<root->data){
        root->left = createBST(root->left, val);
    }
    if(val>root->data){
        root->right = createBST(root->right, val);
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

Node *deleteNode(Node *root, int val){
    if(root == NULL){
        return root;
    }

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else {
        // Case 1: leaf node
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        // Case 2: one child
        else if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: two children
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
