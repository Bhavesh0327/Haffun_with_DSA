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

struct node * unionLL(struct node *p , struct node *q){
	int hash[1000] = {0};
	struct node *head1, *head2;
	head1 = p;
	head2 = q;
	struct node* newLL;
	while(head1!=NULL){
		hash[head1->data]++;
		head1 = head1->next;
	}
	while(head2!=NULL){
		hash[head2->data]++;
		head2 = head2->next;
	}
	for(int i=0;i<1000;i++){
		if(hash[i]>=1){
		newLL = insert(newLL , i);
		}
	}
	return newLL;
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
	head2 = insert(head2 , 2);
	head2 = insert(head2 , 4);
	head2 = insert(head2 , 5);
	head2 = insert(head2 , 6);
	head2 = insert(head2 , 9);
	head2 = insert(head2 , 11);
	head3 = unionLL(head1 , head2); // The new list is the union  of the two linked lists 
	printList(head1);
	printList(head2);
	printList(head3);
	return 0;
}
