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

bool isComplete(node* root){
    if(root==NULL){
        return  true;
    }
    queue<node*> q;
    q.push(root);
    bool flag = false;
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        if(temp->left){
            if(flag==true){
                return false;
            }
            q.push(temp->left);
        }
        else{
            flag = true;
        }
        if(temp->right){
            if(flag==true){
                return false;
            }
            q.push(temp->right);
        }
        else{
            flag = true;
        }
        return false;
    }
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
    if(isComplete(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;  
    
}