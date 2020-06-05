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
int KthNodeFromEnd(node* head, int k){
	struct node* p, *q;
	p = q = head;
	for(int i=0;i<k;i++){
		q = q->next;
		if(q==NULL){
		return -1;
	}
	}
	
	while(q!=NULL){
		q = q->next;
		p = p->next;
	}
	return p->data;
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
	cout << "Enter the node you want to print from end\n";
	cin >> k;
	q = KthNodeFromEnd(x , k);
	if( q== -1){
		cout << "Sorry! k exceeding the limit size\n";
	}
	else cout << q << endl;
	return 0;
}
