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

int len(struct node* head){
	struct node *p;
	p= head;
	int n=0;
	while(p!=NULL){
		p=p->next;
		n++;
	}
	return n;
}
struct node* recursiveReverseLL(node* head){
	struct node* p,*q;
	if( head==NULL || head->next==NULL){
		return head;
	}
	//This one is to reverse the rest of the list
	p = recursiveReverseLL(head->next);
	//This one is to point the reversed linked list to the current head node
	head->next->next = head;
	//This one makes head the last node by pointing it to null
	head->next = NULL;
	//This returns p as the head node of the new list
	return p;
}
int palindrome(struct node * head, int n){
	struct node* p,*q , *v,*w;
	int x;
	p = q = head;
	if(n%2==0){
		x =  n/2 ;
	}
	else{
		x = (n+1)/2;
	}
	for(int i=0;i<x;i++){
			v = q;
			q = q->next;
	}
	v->next =NULL;
	q = recursiveReverseLL(q);
	w = q;
	while(p!=NULL && q!=NULL){
		if(p->data!=q->data){
			w = recursiveReverseLL(w);
			v->next = w;
			return 0;
		}
		p = p->next;
		q = q->next;
	}
	w = recursiveReverseLL(w);
	v->next = w;
	return 1;
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
	cout << "The linked list is : ";
	printList(x);
	if(palindrome(x , len(x))){
		cout << "Yes! it is a palindrome\n" ;
	}
	else{
		cout << "No! It is not a palindrome\n";
	}
	return 0;
}
