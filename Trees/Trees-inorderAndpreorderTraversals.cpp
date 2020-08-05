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

int search(int arr[], int strt, int end, int key){
    int i;  
    for (i = strt; i <= end; i++){  
        if (arr[i] == key)  
            return i;  
    }
    return 0;
}

node* buildTree(int in[], int pre[], int inStart, int inEnd){
    static int preIndex  = 0;
    if(inStart>inEnd){
        return NULL;
    }
    node* root = newNode(pre[preIndex++]);
    if(inStart == inEnd){
        return root;
    }
    int inIndex = search(in, inStart, inEnd, root->data);
    root->left = buildTree(in, pre,inStart, inIndex-1);
    root->right = buildTree(in , pre, inIndex+1 , inEnd);
    return root;
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
    int in[] = {4 , 2 , 5, 1 , 6 , 3};
    int pre[] = {1 , 2 , 4 , 5 , 3 , 6};
    int n = 6;
    node* root = buildTree(in, pre, 0 , n-1);
    inorder(root);
    cout << endl;
    return 0;
}