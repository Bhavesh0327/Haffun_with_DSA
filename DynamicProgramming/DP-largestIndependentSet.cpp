#include<iostream>

using namespace std;

struct node{
    int data;
    int liss;
    struct node* left;
    struct node* right;
};

int lis(struct node* root){
    int ans;
    ans = 0;
    if(root==NULL){
        return 0;
    }
    if (root->liss)  
        return root->liss;      //optimised code 
  
    if (root->left == NULL && root->right == NULL)  
        return (root->liss = 1);
    int left,right;
    left = right = 0;
    if(root->right){
        right = lis(root->right->left)+lis(root->right->right);
    }
    if(root->left){
        left = lis(root->left->right) + lis(root->left->left);
    }
    ans = max(lis(root->right)+lis(root->left) , 1 + left+right);
    return ans;
}

struct node* newNode( int data )  
{  
    struct node* temp = new node(); 
    temp->data = data;  
    temp->left = temp->right = NULL;  
    return temp;  
}

int main(){
    struct node *root = newNode(20);  
    root->left = newNode(8);  
    root->left->left = newNode(4);  
    root->left->right = newNode(12);  
    root->left->right->left = newNode(10);  
    root->left->right->right = newNode(14);  
    root->right = newNode(22);  
    root->right->right = newNode(25);
    cout << lis(root) << endl;
    return 0;
}