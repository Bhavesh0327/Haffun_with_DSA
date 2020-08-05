/**************************************************************
 * Given a Binary Tree where all values are from 0 to n-1. Construct an ancestor matrix mat[n][n]. Ancestor matrix is defined as below.
    mat[i][j] = 1 if i is ancestor of j
    mat[i][j] = 0, otherwise
****************************************************************/
#include<iostream>
#include<bits/stdc++.h>
#define n 100
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

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

bool mat[n][n];
int ancestorMatrixRecur(node* root, vector<int>& anc){
    if(root==NULL){
        return 0;
    }
    int data = root->data;
    for(int i=0;i<anc.size();i++){
        mat[anc[i]][data] = true;
    }
    anc.push_back(data);
    int l = ancestorMatrixRecur(root->left, anc);
    int r = ancestorMatrixRecur(root->right, anc);
    return l+r+1;
}

void ancestorMatrix(node* root){
    vector<int> anc;
    int size = ancestorMatrixRecur(root, anc);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    node *root        = newNode(5); 
    root->left        = newNode(1); 
    root->right       = newNode(2); 
    root->left->left  = newNode(0); 
    root->left->right = newNode(4); 
    root->right->left = newNode(3); 

    ancestorMatrix(root); 
    cout << endl;
    return 0;
}