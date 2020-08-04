/*****************************
 * Two nodes of a BST are swapped, correct the BST
******************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
          
    return(Node); 
}

void correctBSTUtil(node* root, node** first, node** middle, node** prev, node** last){
    if(root){
        correctBSTUtil(root->left, first, middle, prev, last);
        if(*prev && root->data < (*prev)->data){
            if(!*first){
                *first = *prev;
                *middle = root;
            }
            else{
                *last = root;
            }
        }
        *prev = root;
        correctBSTUtil(root->right, first, middle, prev, last);
    }
}

void correctBST(node* root){
    struct node* first, *middle, *last, *prev;
    first = middle = last = prev = NULL;
    correctBSTUtil(root, &first, &middle, &prev, &last);
    if(first&& last){
        swap(first->data, last->data);
    }
    else if(first&&middle){
        swap(first->data, middle->data);
    }
}

void inorder(struct node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    struct node* root;
    root = newNode(20);
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(12); 
    root->left->right = newNode(4);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    inorder(root);
    cout << endl;
    correctBST(root);
    inorder(root);
    cout << endl;
    return 0;  
    
}