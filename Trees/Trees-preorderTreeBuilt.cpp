/**************************************************************
 * Given an array ‘pre[]’ that represents Preorder traversal of a spacial 
 * binary tree where every node has either 0 or 2 children. One more array
 * ‘preLN[]’ is given which has only two possible values ‘L’ and ‘N’.
 * The value ‘L’ in ‘preLN[]’ indicates that the corresponding node in Binary
 * Tree is a leaf node and value ‘N’ indicates that the corresponding node is
 * non-leaf node. Write a function to construct the tree from the given two arrays.
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

node*  buildTreeUtil(int pre[], char preLN[], int* index, int n){
    int in = *index;
    if(in == n){
        return  NULL;
    }
    node *root = newNode(pre[in]);
    (*index)++;
    if(preLN[in]=='N'){
        root->left = buildTreeUtil(pre, preLN, index, n);
        root->right = buildTreeUtil(pre, preLN, index, n);
    }
    return root;
}

node* buildTree(int in[],char preLN[], int n){
    int index = 0;
    return buildTreeUtil(in, preLN, &index , n);
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
    int pre[] = {10, 30, 20, 5 ,15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    node* root = buildTree(pre,preLN, 5);
    preorder(root);
    cout << endl;
    return 0;
}