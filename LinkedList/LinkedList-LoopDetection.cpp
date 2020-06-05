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

bool detectLoop(struct node **head){
	struct node *p, *q;
	p = q = *head;
	while(q!=NULL && q->next!=NULL && p!=NULL){
		p= p->next;
		q = q->next->next;
		if(q == p){
			q->next=NULL;
			return true;
		}
		if(p==NULL || q ==NULL){
			return false;
		}
	}
	return false;
}

int main(){
	struct node *x= NULL;
	x = insert(x,8);
	x = insert(x,4);
	x = insert(x,2);
	x = insert(x,1);
	x = insert(x,19);
	x = insert(x,29);
	x->next->next->next->next->next->next = x->next;
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
	if(detectLoop(&x)){
		cout << "Yes! It has a loop\n";
	}
	else{
		cout << "No loop found\n";
	}
	printList(x);
	if(detectLoop(&x)){
		cout << "Yes! It has a loop\n";
	}
	else{
		cout << "No loop found\n";
	}
	return 0;
}
