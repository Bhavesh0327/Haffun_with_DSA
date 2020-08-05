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

bool printPath(node* root, node* target){
    if(root==NULL){
        return false;
    }
    if(root==target || printPath(root->left, target) || printPath(root->right, target)){
        cout << root->data << " ";
        return true;
    }
    return false;
}

void getTargetLeaf(node* root, int* max_sum, int curr, node** target){
    if(root==NULL){
        return;
    }
    curr = curr + root->data;
    if(root->left==NULL && root->right==NULL){
        if(curr > *max_sum){
            *max_sum = curr;
            *target = root;
        }
    }
    getTargetLeaf(root->left, max_sum, curr, target);
    getTargetLeaf(root->right, max_sum, curr, target);
}

int maxSumPath(node* root){
    if(root==NULL){
        return 0;
    }
    node* target;
    int max_sum = INT_MIN;
    getTargetLeaf(root, &max_sum, 0 , &target);
    printPath(root, target);
    return max_sum;
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
    cout << maxSumPath(root) << endl;
    return 0;
}