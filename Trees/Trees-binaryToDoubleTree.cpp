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

void doubleTree(node* root){  
    node* oldLeft;  
    if (root == NULL) return;  
      
    /* do the subtrees */
    doubleTree(root->left);  
    doubleTree(root->right);
    oldLeft = root->left;  
    root->left = newNode(root->data);  
    root->left->left = oldLeft;  
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
    doubleTree(root);
    preorder(root);
    cout << endl;
    return 0;  
    
}