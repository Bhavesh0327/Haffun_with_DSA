#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

struct node{
	char data;
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

struct node* vowelsAtEnd(struct node* head){
	struct node *p, *q, *temp;
	p = temp = head;
	q = NULL;
	while(p->next!=NULL && p!=NULL){
		temp = p->next;
		if(temp->data=='a' || temp->data=='e' || temp->data=='i' || temp->data=='o' || temp->data=='u' || temp->data=='A' || temp->data=='E' || temp->data=='I' || temp->data=='O' || temp->data=='U'){
			p->next = temp->next;
			q = insert(q,temp->data);
			free(temp);
		}
		p = p->next;
	}
	temp = head;
	if(temp->data=='a' || temp->data=='e' || temp->data=='i' || temp->data=='o' || temp->data=='u' || temp->data=='A' || temp->data=='E' || temp->data=='I' || temp->data=='O' || temp->data=='U')
	{
		head = head->next;
		free(temp);
	}
	p->next = q;
	printList(q);
	return head;
}
int main(){
	struct node *x= NULL;
	int n;
	char s;
	cout << "Enter the number of nodes you want to add:\n" ;
	cin >> n;
	if(n>1){cout << "Enter " << n << " values now: \n";
	}
	else if(n==1){
		cout << "Enter the character now: \n";
	}
	for(int i=0;i<n;i++){
		cin >> s;
		x = insert(x,s); 
	}
	cout << "The linked list is : ";
	printList(x);
	x = vowelsAtEnd(x);
	cout << "The Reversed linked list is : ";
	printList(x);
	return 0;
}
