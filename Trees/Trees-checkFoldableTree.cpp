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

bool isStructSame(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1!=NULL && root2!=NULL && isStructSame(root1->left,root2->left)&& isStructSame(root1->right,root2->right)){
        return true;
    }
    return false;
}

void mirror(node* root){
    if(root==NULL){
        return;
    }
    else{
        node* temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

bool isFoldable(node* root){
    bool ans;
    if(root==NULL){
        return true;
    }
    mirror(root->left);
    ans = isStructSame(root->left , root->right);
    mirror(root->left);
    return ans;
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
    if(isFoldable(root)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;  
    
}