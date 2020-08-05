/**************************************************************
 * Given an ancestor matrix mat[n][n] where Ancestor matrix is defined as below.
    mat[i][j] = 1 if i is ancestor of j
    mat[i][j] = 0, otherwise
****************************************************************/
#include<iostream>
#include<bits/stdc++.h>
#define n 6
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


void preorder(node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node* ancestorTree(int mat[][n]){
    int parent[n] = {0};
    node* root = NULL;
    multimap<int, int> mm;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum+=mat[i][j];
        }
        mm.insert(pair<int,int>(sum,i));
    }
    node* nodes[n];
    for(auto it = mm.begin();it!=mm.end();it++){
        nodes[it->second] = newNode(it->second);
        root = nodes[it->second];
        if(it->first !=0){
            for(int i=0;i<n;i++){
                if(!parent[i] && mat[it->second][i]){
                    if (!nodes[it->second]->left) 
                        nodes[it->second]->left = nodes[i]; 
                    else
                        nodes[it->second]->right = nodes[i]; 
  
                    parent[i] = 1;
                }
            }
        }
    }
    return root;
}

int main(){
    int mat[n][n] = {{ 0, 0, 0, 0, 0, 0 }, 
        { 1, 0, 0, 0, 1, 0 }, 
        { 0, 0, 0, 1, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 0, 0, 0, 0, 0, 0 }, 
        { 1, 1, 1, 1, 1, 0 } 
    };
    node* root = ancestorTree(mat);
    preorder(root);
    cout << endl;
    return 0;
}