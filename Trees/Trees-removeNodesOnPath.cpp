/*********************************************************************
 * Remove all nodes which don’t lie in any path with sum>= k
 *******************************************************************/

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

node* removeUtil(node* root, int k , int *sum){
    if(root==NULL){
        return NULL;
    }
    int ls,rs;
    ls = rs = *sum + root->data;
    root->left = removeUtil(root->left, k , &ls);
    root->right = removeUtil(root->right, k ,&rs);
    *sum = max(ls, rs);
    if(*sum < k){
        free(root);
        root=NULL;
    }
    return root;
}

node* remove(node* root, int k){
    int sum = 0;
    return removeUtil(root, k,&sum);
}

void print(struct node *root){ 
    if (root != NULL) 
    { 
        print(root->left); 
        printf("%d ",root->data); 
        print(root->right); 
    } 
} 

int main(){
    struct node* root;
    root = newNode(1);
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->left->left->left = newNode(8); 
    root->left->left->right = newNode(9); 
    root->left->right->left = newNode(12); 
    root->right->right->left = newNode(10); 
    root->right->right->left->right = newNode(11); 
    root->left->left->right->left = newNode(13); 
    root->left->left->right->right = newNode(14); 
    root->left->left->right->right->left = newNode(15); 
    int k;
    cin >> k;
    print(root);
    cout << endl;
    root = remove(root, k);
    print(root);
    cout << endl;
    return 0;
}