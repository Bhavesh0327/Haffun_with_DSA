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

void kthNode(node* root, int k){
    if(root==NULL){
        return ;
    }
    if(k==0){
        cout << root->data << " ";
        return;
    }
    else{
        kthNode(root->left, k-1);
        kthNode(root->right, k-1);
    }
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
    kthNode(root,2);
    cout << endl;
    return 0;  
}