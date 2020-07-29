#include<iostream>

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

int getSize(struct node* root){
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int l,r;
    l=r=0;
    if(root->left){
        l = getSize(root->left);
    }
    if(root->right){
        r = getSize(root->right);
    }
    return 1+l+r;
}

int main(){
    struct node* root;
    root = newNode(1);
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    cout << "Size of the tree is " << getSize(root);  
    return 0;  
    
}