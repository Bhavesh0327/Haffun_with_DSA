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

void rotate(struct node **head, int k){
	struct node * current, *temp;
	temp = current = *head;
	while(current->next!=NULL){
		current = current->next;
	}
	current->next = temp;
	current =  temp;
	temp = temp->next;
	for(int i=0;i<k-1;i++){
		current = temp;
		temp = temp->next;
	}
	current->next = NULL;
	*head = temp;
}

int main(){
	int k;
	struct node *head1= NULL , *head2 = NULL , *head3 = NULL;
	head1 = insert(head1 , 2);
	head1 = insert(head1 , 3);
	head1 = insert(head1 , 4);
	head1 = insert(head1 , 6);
	head1 = insert(head1 , 7);
	head1 = insert(head1 , 8);
	head1 = insert(head1 , 10);
	head1 = insert(head1 , 13);
	cout << "Please give in the value of k\n";
	cin >> k;
	printList(head1);
	rotate(&head1, k); // Just give k for anti clockwise rotation
	cout << "After rotation Anti-clockwise: " << endl;
	printList(head1);
	rotate(&head1, len(head1)- k); //And give lenght -k for clockwise rotation
	cout << "After rotation Clockwise: " << endl;
	printList(head1);
	return 0;
}
