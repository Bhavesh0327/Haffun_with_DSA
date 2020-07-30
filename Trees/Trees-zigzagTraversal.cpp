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

vector<int> zigzag(node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    stack<node*> current;
    stack<node*> nextLevel;
    current.push(root);
    node* temp;
    bool lefttoright=true;
    while(!current.empty()){
        temp = current.top();
        current.pop();
        if(temp){
            ans.push_back(temp->data);
            if(lefttoright){
                if(temp->left){
                    nextLevel.push(temp->left);
                }
                if(temp->right){
                    nextLevel.push(temp->right); 
                }
            }
            else{
                if(temp->right){
                    nextLevel.push(temp->right); 
                }
                if(temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }
        if(current.empty()){
            lefttoright = !lefttoright;
            swap(current,nextLevel);
        }
    }
    return ans;
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
    vector<int> ans = zigzag(root);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    } 
    return 0;
}