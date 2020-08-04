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

node* kthCount(node* root, int& count, int k){
    if(root==NULL){
        return NULL;
    }
    node* left = kthCount(root->left, count ,k);
    if(left!=NULL){
        return left;
    }
    count++;
    if(count==k){
        return root;
    }
    return kthCount(root->right, count, k);
}

int kthSmallest(node* root , int k){
    int count = 0;
    node* ans = kthCount(root, count, k);
    if(ans==NULL){
        return  -1;
    }
    else{
        return ans->data;
    }
}

/*****************************************************************************
 * One simple approach here can be, we can store the count of left subtree inside the node itself
 * That way we will know how many nodes are smaller than the current root
 * If greater than k, go for root->left, else root>right
Node* kthSmallest(Node* root, int k){ 
    // base case 
    if (root == NULL) 
        return NULL; 
  
    int count = root->lCount + 1; 
    if (count == k) 
        return root; 
  
    if (count > k) 
        return kthSmallest(root->left, k); 
  
    // else search in right subtree 
    return kthSmallest(root->right, k - count); 
}
*****************************************************************************/

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
        int k;
        cin >> k;
        cout << kthSmallest(root , k) << endl;
    }
    return 0;  
    
}