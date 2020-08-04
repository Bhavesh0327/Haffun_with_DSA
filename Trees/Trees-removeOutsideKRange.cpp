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

node* removeOutsideK(node* root, int k1, int k2){
    if(root==NULL){
        return NULL;
    }
    root->left = removeOutsideK(root->left, k1, k2);
    root->right = removeOutsideK(root->right, k1, k2);
    if(root->data < k1){
        node* rChild = root->right;
        delete root;
        return rChild;
    }
    if(root->data >k2){
        node* lChild = root->left;
        delete root;
        return lChild;
    }
    return root;
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
    int k1 , k2;
    cin >> k1 >> k2;
    cout << root->data << endl;
    root = removeOutsideK(root, k1 , k2);
    cout << root->data << endl;
    return 0;
}