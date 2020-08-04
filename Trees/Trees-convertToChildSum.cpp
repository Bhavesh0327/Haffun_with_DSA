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

void increment(node* node, int diff){
    if(node->left != NULL){  
        node->left->data = node->left->data + diff;  
        increment(node->left, diff);  
    }  
    else if (node->right != NULL){  
        node->right->data = node->right->data + diff;  
        increment(node->right, diff);  
    }  
}

void childSum(node* root){
    if(root==NULL || root->left==NULL && root->right==NULL){
        return;
    }
    int diff,l,r;
    l = r  = 0;
    childSum(root->left);
    childSum(root->right);
    if(root->left){
        l = root->left->data;
    } 
    if(root->right){
        r = root->right->data;
    }
    diff = root->data - l - r;
    if(diff>0){
        increment(root , diff);
    }
    else if(diff<0){
        root->data -= diff;
    }
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
    return true;
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
    childSum(root);
    if(isChildSum(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0; 
}