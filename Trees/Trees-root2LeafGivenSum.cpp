#include<iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node* next;
};

struct node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
    Node->next = NULL;
    return(Node);  
} 


bool root2Leaves(node* root, int k){
    if(root==NULL){
        return (k==0);
    }
    else{
        int ans;
        ans = 0;
        int subSum;
        subSum = k - root->data;
        if(subSum==0 && root->left==NULL  && root->right==NULL){
            return 1;
        }
        if(root->left){
            ans= ans|| root2Leaves(root->left, subSum);
        }
        if(root->right){
            ans= ans || root2Leaves(root->right, subSum);
        }
        return ans;
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
    int k;
    cin >> k;
    if(root2Leaves(root, k)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}