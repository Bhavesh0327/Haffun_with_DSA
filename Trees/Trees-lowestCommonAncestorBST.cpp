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

node* lowestCommonAncestor(node* root, int n1, int n2){
    if(root==NULL){
        return  NULL;
    }
    else if(root->data<n1 && root->data < n2){
        return lowestCommonAncestor(root->right, n1, n2);
    }
    else if(root->data>n2 && root->data > n1){
        return lowestCommonAncestor(root->left, n1, n2);
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
    int t;
    cin >> t;
    while(t--){
        int n1, n2;
        cin >> n1 >> n2;
        cout << (lowestCommonAncestor(root , n1, n2))->data << endl;
    }
    return 0;  
    
}