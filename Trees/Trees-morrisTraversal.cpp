/**************************************************************
 * inorder traversal without recursion and stack
****************************************************************/
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

/**************************************************************************
 * 1. Initialize current as root 
 * 2. While current is not NULL
   If the current does not have left child
      a) Print current’s data
      b) Go to the right, i.e., current = current->right
   Else
      a) Make current as the right child of the rightmost 
         node in current's left subtree
      b) Go to this left child, i.e., current = current->left
*****************************************************************************/

void MorrisTraversal(node* root){
    node* curr, *pre;
    if(root==NULL){
        return;
    }
    curr = root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }
        else{
            pre = curr->left;
            while(pre->right!=NULL && pre->right!=curr){
                pre = pre->right;
            }
            if(pre->right==NULL){
                pre->right = curr;
                curr = curr->left;
            }
            else{
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }

}

int main(){
    node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    MorrisTraversal(root);
    return 0;
}