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

struct node* evenAndOdd(struct node **head){
	struct node* newLL ,*temp , *temp1;
	newLL = NULL;
	temp = *head;
	while(temp!=NULL){
		temp1 = temp->next;
		newLL = insert(newLL , temp1->data);
		temp->next = temp->next->next;
		temp = temp->next;
	}
	return newLL;
}

int main(){
	struct node *head = NULL , *newLL=NULL;
	head = insert(head , 2);
	head = insert(head , 0);
	head = insert(head , 2);
	head = insert(head , 0);
	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 0);
	head = insert(head , 0);
	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 1);
	head = insert(head , 0);
	head = insert(head , 2);
	head = insert(head , 0);
	head = insert(head , 1);
	head = insert(head , 0);
	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 0);
	head = insert(head , 0);
	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 0);
	head = insert(head , 1);
	head = insert(head , 1);
	head = insert(head , 2);
	printList(head);
	newLL = evenAndOdd(&head);
	printList(head);
	printList(newLL);
	return 0;
}
