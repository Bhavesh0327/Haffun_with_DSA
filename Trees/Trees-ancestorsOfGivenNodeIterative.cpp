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

void printAncestors(node* root, int target){
    if(root==NULL){
        return ;
    }
    stack<node*> s;
    while(1){
        while(root && root->data!=target){
            s.push(root);
            root = root->left;
        }
        if(root  && root->data == target){
            break;
        }
        if(s.top()->right==NULL){
            root = s.top();
            s.pop();
            while(!s.empty()&& s.top()->right==root){
                root = s.top();
                s.pop();
            }
        }
        root = s.empty() ? NULL: s.top()->right;
    }
    while(!s.empty()){
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
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
    printAncestors(root, 8);
    return 0;
}