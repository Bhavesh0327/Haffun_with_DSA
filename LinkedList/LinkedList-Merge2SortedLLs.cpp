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

struct node * merge(struct node *head1 , struct node *head2){
	struct node *p, *q, *final;
	final = NULL;
	p = head1;
	q = head2;
	while(p!=NULL && q!=NULL){
		if(p->data <= q->data){
			final = insert(final, p->data);
			p = p->next;
		}
		else{
			final = insert(final, q->data);
			q = q->next;
		}
	}
	if(p==NULL){
		while(q!=NULL){
			final = insert(final, q->data);
			q = q->next;		
		}
	}
	else if(q==NULL){
		while(p!=NULL){
			final = insert(final , p->data);
			p = p->next;
		}
	}
	return final;
}

int main(){
	struct node *head1= NULL , *head2 = NULL , *head3 = NULL;
	//first list starts here
	head1 = insert(head1 , 2);
	head1 = insert(head1 , 3);
	head1 = insert(head1 , 4);
	head1 = insert(head1 , 6);
	head1 = insert(head1 , 7);
	head1 = insert(head1 , 8);
	head1 = insert(head1 , 10);
	head1 = insert(head1 , 13);
	//second list starts here
	head2 = insert(head2 , 2);
	head2 = insert(head2 , 4);
	head2 = insert(head2 , 5);
	head2 = insert(head2 , 6);
	head2 = insert(head2 , 9);
	head2 = insert(head2 , 11);
	head3 = merge(head1 , head2); // The new list is the intersection  of the two linked lists 
	printList(head1);
	printList(head2);
	cout << endl;
	cout << "Merged Linked list \n\n";
	printList(head3);
	return 0;
}
