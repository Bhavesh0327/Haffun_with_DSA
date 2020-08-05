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

int largestBSTRecur(node* root, int *min_ref, int *max_ref, int *max_size_ref, bool *is_bst_ref){
    if (root == NULL){  
        *is_bst_ref = 1; // An empty tree is BST  
        return 0; // Size of the BST is 0  
    }

    int min = INT_MAX;
    bool left_flag = false;
    bool right_flag = false;
    int ls, rs;

    *max_ref = INT_MIN;
    ls = largestBSTRecur(root->left, min_ref, max_ref,max_size_ref, is_bst_ref); 
    if(*is_bst_ref == 1 && root->data > *max_ref){
        left_flag = true;
    }
    min = *min_ref;

    *min_ref = INT_MAX;

    rs = largestBSTRecur(root->right, min_ref, max_ref , max_size_ref, is_bst_ref);
    if(*is_bst_ref == 1 && root->data < *min_ref){
        right_flag = true;
    }
    if(min < *min_ref){
        *min_ref = min;
    }
    if(root->data < *min_ref){
        *min_ref = root->data;
    }
    if(root->data > *max_ref){
        *max_ref = root->data;
    }
    if(left_flag && right_flag){
        if(ls + rs +1 > *max_size_ref){
            *max_size_ref = ls+rs+1;
        }
        return ls+rs+1;
    }
    else{
        *is_bst_ref = 0;
        return 0;
    }
}

int largestBST(node* root){
    int min = INT_MAX;
    int max = INT_MIN;
    int max_size = 0;
    bool is_bst = false;
    largestBSTRecur(root , &min, &max, &max_size, &is_bst);
    return max_size;
}

int main(){
    node *root = newNode(50);  
    root->left = newNode(10);  
    root->right = newNode(60);  
    root->left->left = newNode(5);  
    root->left->right = newNode(20);  
    root->right->left = newNode(55);  
    root->right->left->left = newNode(45);  
    root->right->right = newNode(70);  
    root->right->right->left = newNode(65);  
    root->right->right->right = newNode(80);
    cout << largestBST(root) << endl;
    return 0;  
    
}