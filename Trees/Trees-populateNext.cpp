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

void populateNext(node* root){
    static node* next = NULL;
    if(root){
        populateNext(root->right);
        root->next = next;
        next = root;
        populateNext(root->left);
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
    populateNext(root);
    node *ptr = root->left->left;  
    while(ptr){
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1)  
             << endl;  
        ptr = ptr->next;  
    } 
    return 0;  
    
}