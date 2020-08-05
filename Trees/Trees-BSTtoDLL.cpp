#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
          
    return(Node); 
}

node* bst2dll(node* root){
    if(root==NULL){
        return root;
    }
    if(root->left!=NULL){
        node* left = bst2dll(root->left);
        for(; left->right!=NULL; left = left->right);
        left->right = root;
        root->left = left;
    }
    if(root->right!=NULL){
        node* right = bst2dll(root->right);
        for(; right->left!=NULL; right = right->left);
        right->left = root;
        root->right = right;
    }
    return root;
}

node* b2d(node* root){
    if(root==NULL){
        return root;
    }
    root = bst2dll(root);
    while(root->left !=NULL){
        root = root->left;
    }
    return  root;
}

void printdll(node* root){
    node* temp;
    temp = root;
    while(root!=NULL){
        cout << root->data << " ";
        temp = root;
        root = root->right;
    }
    cout << endl;
    root = temp;
    while(root!=NULL){
        cout << root->data << " ";
        root = root->left;
    }
    cout << endl;
}

int main(){
    struct node* root;
    root = newNode(20);
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4); 
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    struct node* head;
    head = b2d(root);
    printdll(head);
    return 0;
}