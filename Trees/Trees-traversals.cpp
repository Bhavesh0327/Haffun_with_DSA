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


void inorder(struct node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(struct node* root){
    if(root==NULL){
        return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root){
    if(root==NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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
    int height =0;
    inorder(root);  
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;  
    
}