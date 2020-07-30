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

int diff(node* root){
    queue<node*> q;
    int size,even, odd, level;
    even=odd=level=0;
    if(root==NULL){
        return 0;
    }
    q.push(root);
    while(!q.empty()){
        size = q.size();
        level+=1;
        while(size--){
            node* temp;
            temp = q.front();
            q.pop();
            if(level%2==0){
                even +=temp->data;
            }
            else{
                odd+=temp->data;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return (odd-even);          // In this particular question absolute isn't necessary
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
    cout << "Difference between sums of even level and odd level elemtents is : " << diff(root) << endl;  
    return 0;  
    
}