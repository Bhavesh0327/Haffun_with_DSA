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

bool isBalancedUtil(node* root, int * h){
    int lh, rh,l,r;
    lh=rh=0;
    if(root==NULL){
        *h = 0;
        return 1;
    }
    l=r=0;
    if(root->left){
        l = isBalancedUtil(root->left, &lh);
    }
    if(root->right){
        r = isBalancedUtil(root->right,&rh);
    }
    *h = (lh>rh ? lh :rh )+1;
    if(abs(lh-rh)>=2){
        return 0;
    }
    else{
        return l&&r;
    }
}

bool isBalanced(node* root){
    if(root==NULL){
        return 1;
    }
    int h;
    h = 0;
    return isBalancedUtil(root , &h);
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
    if(isBalanced(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;  
    
}