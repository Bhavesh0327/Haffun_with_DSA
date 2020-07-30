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

bool sameLevel(node* root){
    if(root==NULL){
        return false;
    }
    vector<int> ans;
    queue<node*> q;
    q.push(root);
    int level,size;
    level=0;
    node* temp;
    while(!q.empty()){
        size = q.size();
        level+=1;
        while(size--){
            temp = q.front();
            q.pop();
            if(temp->left==NULL && temp->right==NULL){
                ans.push_back(level);
            }
            else{
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
        }
    }
    for(int i=1;i<ans.size();i++){
        if(ans[i]!=ans[0]){
            return  false;
        }
    }
    return true;
}

int main(){
    struct node* root;
    root = newNode(1);
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);
    // root->right->right = newNode(6);
    if(sameLevel(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;  
    
}