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
unordered_map<node*, node*> parent;
void travel(node* root){
    if(root->left!=NULL){
        parent[root->left]=root;
        travel(root->left);
    }
    if(root->right!=NULL){
        parent[root->right]=root;
        travel(root->right);
    }
}
node* lowestCommonAncestor(node* root, node* p, node* q) {
    if(root==NULL){
        return NULL;
    }
    travel(root);
    vector<node*> l,r;
    while(parent[p]!=NULL){
        l.push_back(p); p = parent[p];
    }
    while(parent[q]!=NULL){
        r.push_back(q); q = parent[q];
    }
    for(int i=0;i<l.size();i++){
        for(int j=0;j<r.size();j++){
            if(l[i]==r[j]){
                return l[i];
            }
        }
    }
    return  root;
}

/*************************************************************************
 * Node* lca(Node* root ,int n1 ,int n2 )
{
    Node *lnode, *rnode;
    if(!root){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    lnode = lca(root->left, n1, n2);
    rnode = lca(root->right, n1, n2);
    if(lnode && rnode){
        return root;
    }

    return (lnode != NULL) ? lnode : rnode;
}
***************************************************************************/

int main(){
    struct node* root;
    root = newNode(20);
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4); 
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << lowestCommonAncestor(root ,root->left->right->left, root->left->right->right)->data << endl;
    return 0;  
    
}