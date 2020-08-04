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

void printNearNodes(node* root, int k1 , int k2){
    if(root==NULL){
        return;
    }
    if(root->data>k1){
        printNearNodes(root->left, k1, k2);
    }
    if(root->data<=k2 && root->data>=k1){
        cout << root->data << " ";
    }
    if(root->data<k2){
        printNearNodes(root->right, k1 , k2);
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
    int t;
    cin >> t;
    while(t--){
        int k1 , k2;
        cin >> k1 >> k2;
        printNearNodes(root, k1 , k2);
        cout << endl;
    }
    return 0;  
    
}