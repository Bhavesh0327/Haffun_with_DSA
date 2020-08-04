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

/*****************************************************************************
 * bool isBST(Node* root, Node* l=NULL, Node* r=NULL) 
{ 
    // Base condition 
    if (root == NULL) 
        return true; 
  
    // if left node exist then check it has 
    // correct data or not i.e. left node's data 
    // should be less than root's data 
    if (l != NULL and root->data <= l->data) 
        return false; 
  
    // if right node exist then check it has 
    // correct data or not i.e. right node's data 
    // should be greater than root's data 
    if (r != NULL and root->data >= r->data) 
        return false; 
  
    // check recursively for every node. 
    return isBST(root->left, l, root) and 
           isBST(root->right, root, r); 
} 
*******************************************************************/

bool isBSTUTIL(node* root, int min , int max){
    if(root==NULL){
        return true;
    }
    if (root->data < min || root->data > max)  
        return 0;
    return isBSTUTIL(root->left, min , root->data-1) && isBSTUTIL(root->right,root->data+1, max);
}

bool isBST(node * root){
    return isBSTUTIL(root , INT_MIN, INT_MAX);
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
    if(isBST(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;  
    
}