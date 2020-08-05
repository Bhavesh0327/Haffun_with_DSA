#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
};

struct node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
    Node->next = NULL;
    return(Node);  
} 

bool printAncestors(node* root, int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    if(printAncestors(root->left, target) || printAncestors(root->right, target)){
        cout << root->data << " ";
        return true;
    }
    return false;
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
    printAncestors(root, 8);
    cout << endl;
    return 0;
}