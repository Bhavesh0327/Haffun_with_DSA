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

int intersectPoint(struct node* head1, struct node *head2){
	int l1, l2,d;
	struct node *p, *q;
	p = head1;
	q = head2;
	l1 = len(head1);
	l2 = len(head2);
	if(l1 > l2){
		d = l1-l2;
		for(int i=0;i<d;i++){
			p= p->next;
		}
		while(p!=NULL && q!=NULL){
			p = p->next;
			q = q->next;
			if(p==q){
				return p->data;
			}
		}
	}
	else{
		d = l2-l1;
		for(int i=0;i<d;i++){
			p= p->next;
		}
		while(p!=NULL && q!=NULL){
			p = p->next;
			q = q->next;
			if(p==q){
				return p->data;
			}
		}
	}
	return -1;
}

int main(){
	struct node *head1= NULL , *head2 = NULL;
	head1 = insert(head1,8);
	head2 = insert(head2,4);
	head1 = insert(head1,2);
	head2 = insert(head2,1);
	head1 = insert(head1,19);
	head2 = insert(head2,29);
	head2 = insert(head2,19);
	head1 = insert(head1,29);
	head1->next->next->next = head2->next ;
	printList(head1);
	printList(head2);
	cout << intersectPoint(head1 , head2) << endl;
	return 0;
}
