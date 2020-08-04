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

int isLeaf(node *node){ 
    if(node == NULL) 
        return 0; 
    if(node->left == NULL && node->right == NULL) 
        return 1; 
    return 0; 
}

bool sumTree(node* root){
    if(root==NULL){
        return true;
    }
    int l,r;
    l = r = 0;
    if(sumTree(root->left)&& sumTree(root->right)){
        if(root->left){
            if(root->left==NULL){
                l = 0;
            }
            else if(isLeaf(root->left)){
                l = root->left->data;
            }
            else{
                l = 2*root->left->data;
            }
        }
        if(root->right){
            if(root->right==NULL){
                r = 0;
            }
            else if(isLeaf(root->right)){
                r = root->right->data;
            }
            else{
                r = 2*root->right->data;
            }
        }
        return (root->data = l+r);
    }
    return false;
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
    if(sumTree(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;  
    
}