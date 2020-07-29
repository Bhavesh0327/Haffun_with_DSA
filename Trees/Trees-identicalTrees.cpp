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

int isIdentical(struct node* head1, struct node* head2){
    if(head1==NULL && head2==NULL){
        return 1;
    }
    return ((head1 && head2) &&
            (head1->data == head2->data) && 
            isIdentical(head1->left,head2->left) &&
            isIdentical(head1->right,head2->right));
}

int main(){
    struct node* root1, *root2;
    root1 = newNode(1);
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->left->left = newNode(4);  
    root1->right->right = newNode(5);  
    root1->right->left = newNode(7);
    root2 = newNode(1);
    root2->left = newNode(2);
    if(isIdentical(root1,root2)){
        cout << "Identical\n";
    }
    else{
        cout << "Not Identical\n";
    }  
    return 0;  
    
}