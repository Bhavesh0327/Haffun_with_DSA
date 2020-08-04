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

void modifyBST(node* root, int *sum){
    if(root==NULL){
        return ;
    }
    modifyBST(root->right,sum);
    *sum = *sum + root->data;
    root->data = *sum;
    modifyBST(root->left, sum);
}

void addGreater(node* root){  
    int sum = 0;
    modifyBST(root , &sum);
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
    struct node* root;
    root = newNode(1);
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->right->right = newNode(5);  
    root->right->left = newNode(7);
    root->right->left->left = newNode(8);
    root->right->left->right = newNode(6);
    addGreater(root);
    preorder(root);
    cout << endl;
    return 0;  
    
}