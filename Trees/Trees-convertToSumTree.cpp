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


int toSum(node* root){
    if(root==NULL){
        return 0;
    }
    int old;
    old = root->data;
    root->data = toSum(root->left) + toSum(root->right);
    return old+root->data;
}

void preorder(struct node* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
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
    preorder(root);
    cout << endl;
    toSum(root);
    preorder(root);
    cout << endl;
    return 0; 
}