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

int minBST(node* root){
    if(root==NULL){
        return  0;
    }
    if(root->left==NULL){
        return root->data;
    }
    else{
        minBST(root->left);
    }
}

//Non recursive approach 

/*
int minValue(node* root)
{
    node* temp;
    temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp->data;
}
*/

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
    cout << minBST(root) << endl; 
    return 0;  
    
}