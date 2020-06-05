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

struct node* reverseInK(struct node* head, int k){
	int  x = k;
	struct node* current ,*temp, *p, *q, *main;
	main = head;
	for(int i=1;i<k;i++){
		main = main->next;
	}
	current = head;
	p = temp = NULL;
	q = current->next;
	while(current!=NULL  && x--){
		current->next = p;
		p = current;
		current = q;
		if(q!=NULL){
		q = q->next;
		}
		else{
			if(temp!=NULL){
			temp->next = p;
			}
		}
		if(x==0){
			if(temp!=NULL){
				temp->next = p;
			}
			temp = head;
			head = current;
			x = k;
			p = NULL;
		}
	}
	return main;
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
//	x = insert(x,23);
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
	x = reverseInK(x,k);
	cout << "The Reversed linked list is : ";
	printList(x);
	return 0;
}
