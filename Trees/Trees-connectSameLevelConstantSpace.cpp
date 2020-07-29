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

node* getNext(node* root){
    node* temp;
    temp = root->next;
    while(temp){
        if(temp->left){
            return temp->left;
        }
        else if(temp->right){
            return temp->right;
        }
        temp = temp->next;
    }
}

void connectRecur(node* root){
    if(!root) return ;
    if(root->next){
        connectRecur(root->next);
    }
    if(root->left){
        if(root->right){
            root->left->next=root->right;
            root->right->next = getNext(root);
        }
        else{
            root->left->next = getNext(root);
        }
        connectRecur(root->left);
    }
    else if(root->right){
        root->right->next = getNext(root);
        connectRecur(root->right);
    }
    else{
        connectRecur(getNext(root));
    }
}

void connect(node* root){
    root->next = NULL;
    connectRecur(root);
}

**********************************************************************/

void connect(node *p)
{
    queue <node*> q;
    q.push(p);
    
    node* prev=NULL;
    node* end = p, *nextend;
    
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->left) { q.push(temp->left); nextend = temp->left; }
        if(temp->right){ q.push(temp->right); nextend = temp->right; }
        
        if(prev) prev->next = temp;
        if(temp == end)
        {
            temp->next = NULL;
            prev = NULL;
            end = nextend;
        }
        else prev = temp;
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