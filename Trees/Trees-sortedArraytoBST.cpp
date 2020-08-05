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

node* array2bst(int arr[], int l, int h){
    if(l>h){
        return NULL;
    }
    int mid = (l+h)/2;
    node* root = newNode(arr[mid]);
    root->left = array2bst(arr, l, mid-1);
    root->right = array2bst(arr, mid+1, h);
    return root;
}

void preorder(struct node* root){
    if(root==NULL){
        return ;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        node* root = array2bst(arr, 0 , n-1);
        preorder(root);
        cout << endl;
    }
    return 0;
}