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


void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printPath(node* root, int arr[], int len){
    if(root==NULL){
        return ;
    }
    arr[len] = root->data;
    len++;
    if(root->left==NULL && root->right==NULL){
        print(arr, len);
    }
    else{
        printPath(root->left, arr, len);
        printPath(root->right, arr, len);
    }
}

void root2Leaves(node* root){
    int path[1001];
    printPath(root, path, 0);
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
    root2Leaves(root); 
    return 0;
}