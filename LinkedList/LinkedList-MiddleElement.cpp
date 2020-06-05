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

void printMiddle(struct node *head){
	struct node *p,*q;
	p = q = head;
	if(head!=NULL){
	while( q!=NULL && q->next!=NULL ){
		q = q->next->next;
		p = p->next;
	}
	cout << "The middle element is: " << p->data << endl;
}
}

int main(){
	struct node *x= NULL;
	x = insert(x,8);
	x = insert(x,4);
	x = insert(x,2);
	x = insert(x,1);
	x = insert(x,19);
	x = insert(x,29);
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
	printMiddle(x);
	printList(x);
	return 0;
}
