/**************************************************************
 * Given two arrays that represent preorder and postorder
 * traversals of a full binary tree, construct the binary tree.
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

node*  buildTreeUtil(int pre[], int post[], int* index,int l, int h, int n){
    if(l>h || *index>=n){
        return NULL;
    }
    node* root = newNode(pre[*index]);
    ++*index;
    if(l==h){
        return root;
    }
    int i;
    for(i=l;i<=h;i++){
        if(pre[*index]==post[i])
            break;
    }
    if(i<=h){
        root->left = buildTreeUtil(pre, post, index, l , i , n);
        root->right = buildTreeUtil(pre, post, index, i+1, h , n);
    }
    return root;
}

node* buildTree(int pre[],int post[], int n){
    int index = 0;
    return buildTreeUtil(pre, post, &index ,0, n-1, n);
}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    node* root = buildTree(pre,post, 9);
    preorder(root);
    cout << endl;
    return 0;
}