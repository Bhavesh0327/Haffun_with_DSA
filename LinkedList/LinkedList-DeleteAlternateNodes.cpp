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

void deleteAlternateNodes(struct node **p){
	struct node *temp, *current;
	current = *p;
	while(current!=NULL){
		temp = current->next;
		current->next= current->next->next;
		current = current->next;
		free(temp);
	}
}

int main(){
	struct node *head1= NULL , *head2 = NULL , *head3 = NULL;
	head1 = insert(head1 , 2);
	head1 = insert(head1 , 3);
	head1 = insert(head1 , 4);
	head1 = insert(head1 , 6);
	head1 = insert(head1 , 7);
	head1 = insert(head1 , 8);
	head1 = insert(head1 , 10);
	head1 = insert(head1 , 13);
	printList(head1);
	deleteAlternateNodes(&head1);
	printList(head1);
	return 0;
}
