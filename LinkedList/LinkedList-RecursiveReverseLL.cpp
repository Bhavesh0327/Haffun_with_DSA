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
	x = recursiveReverseLL(x);
	cout << "The Reversed linked list is : ";
	printList(x);
	return 0;
}
