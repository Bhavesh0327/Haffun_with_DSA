/**************************************************************************
 * Convert a BST to a Binary Tree such that sum of all greater keys is added to every key
***************************************************************************/
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

void convertUtil(node* root, int* sum){
    if(root==NULL){
        return;
    }
    convertUtil(root->right, sum);
    *sum = *sum + root->data;
    root->data = *sum;
    convertUtil(root->left, sum);
}

void convert(node* root){
    int sum=0;
    convertUtil(root, &sum);
}
void inorder(struct node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    inorder(root);
    cout << endl;
    convert(root);
    inorder(root);
    cout << endl;
    return 0;  
    
}