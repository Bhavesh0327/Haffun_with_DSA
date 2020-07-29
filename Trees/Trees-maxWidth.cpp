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

int getWidth(struct node* root, int level){
    if(root==NULL){
        return 0;
    }
    if(level==1){
        return 1;
    }
    int ans;
    if(level>1){
        ans= getWidth(root->left,level-1) + getWidth(root->right,level-1);
    }
    return ans;
}

int getMaxWidth(struct node* root){
    int maxWidth = 0;
    for(int i=1;i<=getHeight(root);i++){
        maxWidth = max(maxWidth,getWidth(root,i));
    }
    return maxWidth;
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
    cout << "Max width of the tree is " << getMaxWidth(root) << endl;  
    return 0;  
    
}