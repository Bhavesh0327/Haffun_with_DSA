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

void reverseLevel(node* root){
    queue<node*> q;
    q.push(root);
    stack<int> Stack;

    while(!q.empty())
    {
        node* Current_Node = q.front();
        q.pop();
        Stack.push(Current_Node->data);

        if(Current_Node->right!=NULL) q.push(Current_Node->right);
        if(Current_Node->left!=NULL) q.push(Current_Node->left);
    }

    while(!Stack.empty())
    {
        cout<<Stack.top()<<" ";
        Stack.pop();
    }
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
    reverseLevel(root);  
    return 0;
}