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

void sum(node* root, int hd, map<int,int>& mp){
    if(root==NULL) return;
    sum(root->left,hd-1,mp);
    mp[hd] += root->data;
    sum(root->right,hd+1,mp);
}


vector<int> verticalSum(node* root){
    vector<int> ans;
    map<int,int> mp;
    map<int,int>::iterator l;
    sum(root,0,mp);
    for(l=mp.begin();l!=mp.end();++l){
        ans.push_back(l->second);
    }
    return ans;
}

int main(){
    struct node* root;
    root = newNode(1);
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    vector<int> ans;
    ans = verticalSum(root);
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;  
    
}