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

/**************************************************************************************

// int getHeight(struct node* root){
//     if(root->left==NULL && root->right==NULL){
//         return 1;
//     }
//     int l,r;
//     l=r=0;
//     if(root->left){
//         l = getHeight(root->left);
//     }
//     if(root->right){
//         r = getHeight(root->right);
//     }
//     return 1+max(l,r);
// }

// void printLevel(node* root, int level){
//     if(root==NULL){
//         return ;
//     }
//     if(level==1){
//         cout << root->data << " ";
//     }
//     else{
//         printLevel(root->left,level-1);
//         printLevel(root->right,level-1);
//     }
// }

// void levelOrder(node* root){
//     int d;
//     for(d=1;d<=getHeight(root);++d){
//         printLevel(root,d);
//     }
// }

****************************************************************************************/

void levelOrder(node* root){
    if(root==NULL) return;
    queue<node*> q;
    q.push(root);
    while(q.empty()==false){
        node* temp;
        temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        if(temp->right!=NULL){
            q.push(temp->right);
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
    levelOrder(root);  
    return 0;  
    
}