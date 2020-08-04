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

bool pairSum(node *root, int sum){
    stack<node*> s1, s2;
    int val1, val2;
    val1 = val2 = 0;
    node* curr1 = root, *curr2 = root;
    bool done1 = false, done2 = false;
    while(1){
        //inorder Traversal inside the stack s1
        while(done1==false){
            if(curr1!=NULL){
                s1.push(curr1);
                curr1 = curr1->left;
            }
            else{
                if(s1.empty()){
                    done1 = true;
                }
                else{
                    curr1 = s1.top();
                    s1.pop();
                    val1 = curr1->data;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }

        // reverse inorder traversal inside s2
        while(done2==false){
            if(curr2!=NULL){
                s2.push(curr2);
                curr2 = curr2->right;
            }
            else{
                if(s2.empty()){
                    done2 = true;
                }
                else{
                    curr2 = s2.top();
                    s2.pop();
                    val2 = curr2->data;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }
        if((val1!=val2) && ((val1 + val2) == sum)){
            return 1;
        }
        else if((val1+val2) < sum){
            done1 = false;
        }
        else if((val1 + val2)>sum){
            done2 = false;
        }
        if(val1>=val2){
            return false;
        }
    }
}

int main(){
    struct node* root;
    root = newNode(20);
    root->left = newNode(8);  
    root->right = newNode(22);  
    root->left->left = newNode(4); 
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    int t;
    cin >> t;
    while(t--){
        int sum;
        cin >> sum;
        if(pairSum(root,sum)){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
    return 0;  
    
}