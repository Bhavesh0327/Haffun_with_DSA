#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;
    return(Node);  
} 

int count(node* head){
    int count=0;
    while(head){
        count++;
        head = head->right;
    }
    return  count;
}

void push(node** head, int data){
    node* temp = newNode(data);
    temp->left = NULL;
    temp->right = *head;
    if(*head!=NULL){
        (*head)->left = temp;
    }
    *head = temp;
}

node* dll2bstRecur(node** head, int n){
    if(n<=0){
        return NULL;
    }
    node* l = dll2bstRecur(head, n/2);
    node* root = *head;
    root->left = l;
    *head = (*head)->right;
    root->right = dll2bstRecur(head, n - n/2 -1);
    return root;
}

node* dll2bst(node* root){
    int n = count(root);
    return dll2bstRecur(&root, n);
}

void preorder(struct node* root){
    if(root==NULL){
        return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* head = NULL; 
    push(&head, 7);  
    push(&head, 6);  
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);
    node* root = dll2bst(head);
    preorder(root);
    return 0;
}