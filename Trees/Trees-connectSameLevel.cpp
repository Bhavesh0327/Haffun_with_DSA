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
/*********************************************************************************
This method works only for Complete Binary Trees


void connectRecur(node* root){
    if(!root) return ;
    if(root->left){
        root->left->next = root->right;
    }
    if(root->right){
        root->right->next = (root->next)?root->next->left:NULL;
    }
    connectRecur(root->left);
    connectRecur(root->right);
}

void connect(node* root){
    root->next = NULL;
    connectRecur(root);
}

****************************************************************************/

void connect(node* root){
    if(root==NULL) return ;
    queue<node*> q;
    q.push(root);
    node* temp=NULL;
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            node* prev = temp;
            temp = q.front();
            q.pop();
            if(i>0){
                prev->next = temp;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
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
    connect(root);  
    return 0;
}