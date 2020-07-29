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
          
    return(Node);  
} 

int getHeight(struct node* root){
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    int l,r;
    l=r=0;
    if(root->left){
        l = getHeight(root->left);
    }
    if(root->right){
        r = getHeight(root->right);
    }
    return 1+max(l,r);
}

void printLevel(node* root, int level, bool x){
    if(root==NULL){
        return ;
    }
    if(level==1){
        cout << root->data << " ";
    }
    else{
        if(x){
            printLevel(root->left,level-1,x);
            printLevel(root->right,level-1,x);
        }
        else{
            printLevel(root->right,level-1,x);
            printLevel(root->left,level-1,x);
        }
    }
}

void printSpiral(node* root){
    int d;
    bool ltr;
    ltr = false;
    for(d=1;d<=getHeight(root);++d){
        printLevel(root,d,ltr);
        ltr = !ltr;
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
    printSpiral(root);  
    return 0;  
    
}