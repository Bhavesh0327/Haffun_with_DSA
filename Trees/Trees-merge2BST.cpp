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

void storeInorder(node* root , int arr[], int* index){
    if(root==NULL){
        return ;
    }
    storeInorder(root->left, arr, index);
    arr[*index] = root->data;
    (*index)++;
    storeInorder(root->right, arr, index);
}

int *merge(int arr1[], int arr2[], int m, int n){
    int *mergedArr = new int[m+n];
    int i=0 , j=0 , k=0;
    while(i<m && j < n){
        if (arr1[i] < arr2[j]){  
            mergedArr[k] = arr1[i];  
            i++;  
        }  
        else{  
            mergedArr[k] = arr2[j];  
            j++;  
        }  
        k++;
    }
    while(i<m){
        mergedArr[k++] = arr2[i++];
    }
    while(j<n){
        mergedArr[k++] = arr1[j++];
    }
    return mergedArr;
}

node* sortedArrayToBST(int arr[], int l , int h){
    if(l>h){
        return NULL;
    }
    int mid = (l+h)/2;
    node* root = newNode(arr[mid]);
    root->left = sortedArrayToBST(arr, l , mid-1);
    root->right = sortedArrayToBST(arr, mid+1, h);
    return root;
}

node* mergeTrees(node* root1, node* root2, int m, int n){
    int *arr1 = new int[m];
    int i=0;
    storeInorder(root1 , arr1, &i);

    int *arr2 = new int[n];
    int j=0;
    storeInorder(root2, arr2 ,&j);
    int *mergedArr = merge(arr1, arr2, m ,n);
    return sortedArrayToBST(mergedArr, 0 , m+n-1);
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
    node *root1 = newNode(100);  
    root1->left = newNode(50);  
    root1->right = newNode(300);  
    root1->left->left = newNode(20);  
    root1->left->right = newNode(70);  
    /**************************************/
    node *root2 = newNode(80);  
    root2->left     = newNode(40);  
    root2->right = newNode(120);  
  
    node *mergedTree = mergeTrees(root1, root2, 5, 3);   
    preorder(mergedTree);  
    return 0;
}