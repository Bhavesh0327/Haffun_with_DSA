#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node{
	int data;
	node* next;
};
struct node* insert(node* head, int x){
	struct node* p,*q;
	p = new node();
	p->data = x;
	if(head == NULL){
		head = p;
	}
	else{
		q = head;
		while(q->next!=NULL){
			q = q->next;
		}
		q->next = p;
	}
	return head;
}
void printList(node* head){
	struct node*p;
	p = head;
	while(p!=NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

struct node* AltreverseInK(struct node* head, int k){
	struct node* current = head;  
    struct node* next;  
    struct node* prev = NULL;  
    int count = 0;  
  
    while (current != NULL && count < k)  
    {  
    next = current->next;  
    current->next = prev;  
    prev = current;  
    current = next;  
    count++;  
    }  
    if(head != NULL)  
    head->next = current;  
  	count = 0;  
    while(count < k-1 && current != NULL )  
    {  
    current = current->next;  
    count++;  
    }  
    if(current != NULL)  
    current->next = AltreverseInK(current->next, k);  
    return prev;  
}

int main(){
	struct node *x= NULL;
	x = insert(x,8);
	x = insert(x,4);
	x = insert(x,2);
	x = insert(x,1);
	x = insert(x,19);
	x = insert(x,54);
	x = insert(x,34);
	x = insert(x,12);
	x = insert(x,32);
	x = insert(x,23);
	int n,s,k,q;
	cout << "Enter the number of nodes you want to add more:\n" ;
	cin >> n;
	if(n>1){cout << "Enter " << n << " numbers now: \n";
	}
	else if(n==1){
		cout << "Enter the number now: \n";
	}
	for(int i=0;i<n;i++){
		cin >> s;
		x = insert(x,s); 
	}
	cout << "Please enter the value of k:\n";
	cin >> k; 
	cout << "The linked list is : ";
	printList(x);
	x = AltreverseInK(x,k);
	cout << "The Reversed linked list is : ";
	printList(x);
	return 0;
}
