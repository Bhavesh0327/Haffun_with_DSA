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

node* inorderSuc(node *root, node* x){
    node* p=NULL;//last left ancestor's parent

    while(root && root!=x)
    {
        if(root->data<x->data)
        root=root->right;
        else
        {
            p=root;
            root=root->left;
        }
    }
    if(!root) return NULL;//No X found
    if(!root->right) return p;
    
    root=root->right;//if x has right child then Inorder Successor
                    //  will be left-most Node of right Subtree
    while(root->left)
    root=root->left;
    
    return root;
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
    return 0;  
    
}