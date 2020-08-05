/**************************************************************
 * Given Inorder Traversal of a Special Binary Tree in which key of every node is 
 * greater than keys in left and right children,
 * construct the Binary Tree and return root.
****************************************************************/
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

node*  buildTreeUtil(int in[], int l , int h){
    if(l>h){
        return NULL;
    }
    node* root;
    int i,index, max_val = INT_MIN;
    for(i=l;i<=h;i++){
        if(in[i]>max_val){
            max_val = in[i];
            index = i;
        }
    }
    root = newNode(max_val);
    root->right = buildTreeUtil(in, index+1, h);
    root->left = buildTreeUtil(in, l , index-1);
    return root;
}

node* buildTree(int in[], int n){
    node* root = buildTreeUtil(in, 0 , n-1);
    return root;
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    int in[] = {5, 10, 40, 30, 28};
    node* root = buildTree(in, 5);
    inorder(root);
    cout << endl;
    return 0;
}