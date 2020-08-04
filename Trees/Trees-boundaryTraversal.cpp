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

void boundaryLeft(node* root, vector<int>& v){
    if(root==NULL){
        return  ;
    }
    if(root->left){
        v.push_back(root->data);
        boundaryLeft(root->left,v);
    }
    else if(root->right){
        v.push_back(root->data);
        boundaryLeft(root->right,v);
    }
}

void boundaryRight(node* root, vector<int>&v){
    if(root==NULL){
        return ;
    }
    if(root->right){
        boundaryRight(root->right, v);
        v.push_back(root->data);
    }
    else if(root->left){
        boundaryRight(root->left, v);
        v.push_back(root->data);
    }
}

void boundaryLeaves(node* root, vector<int>& v){
    if(root==NULL){
        return ;
    }
    boundaryLeaves(root->left,v);
    if(!(root->left)&& !(root->right)){
        v.push_back(root->data);
    }
    boundaryLeaves(root->right, v);
}

vector<int> boundaryTraversal(node* root){
    vector<int> v;
    if(root==NULL){
        return v;
    }
    v.push_back(root->data);
    boundaryLeft(root->left,v);
    boundaryLeaves(root->left,v);
    boundaryLeaves(root->right,v);
    boundaryRight(root->right,v);
    return v;
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
    vector<int> ans;
    ans = boundaryTraversal(root);
    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;  
    
}