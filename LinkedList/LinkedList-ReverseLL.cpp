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
	cout << "The linked list is : ";
	struct node*p;
	p = head;
	while(p!=NULL){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

struct node* reverseLL(node* head){
	struct node *p, *q,*current;
	p = q = NULL;
	current =head;
	while(current!=NULL){
		p = current->next;
		current->next = q;
		q = current;
		current = p;
	}
	current = q; // This one is important as the last node i.e. head is pointing to null right now, and not connected with the list
	return current;
}
int main(){
	struct node *x= NULL;
	x = insert(x,8);
	x = insert(x,4);
	x = insert(x,2);
	x = insert(x,1);
	x = insert(x,19);
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
	printList(x);
	x = reverseLL(x);
	printList(x);
	return 0;
}
