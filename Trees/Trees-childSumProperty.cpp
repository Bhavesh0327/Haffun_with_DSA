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

bool isChildSum(node* root){
    if(root==NULL || (root->left == NULL && root->right==NULL)){
        return true;
    }
    int l,r;
    l = r = 0;
    if(root->left){
        l = root->left->data;
    }
    if(root->right){
        r = root->right->data;
    }
    if(isChildSum(root->left)&&isChildSum(root->right)){
        return  (root->data==l+r);
    }
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
    if(isChildSum(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0; 
}