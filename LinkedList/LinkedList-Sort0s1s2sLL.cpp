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

void sort(struct node **head){
	int hash[3] = {0};
	struct node* p;
	p = *head;
	while(p!=NULL){
		hash[p->data]++;
		p = p->next;
	}
	*head = NULL;
	for(int i=0;i<3;i++){
		while(hash[i]){
			*head = insert(*head , i);
			hash[i]--;
		}
	}
}

int main(){
	struct node *head = NULL;
	head = insert(head , 2);
	head = insert(head , 0);
	head = insert(head , 1);
	head = insert(head , 1);
	head = insert(head , 2);
	head = insert(head , 2);
	head = insert(head , 1);
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
	sort(&head);
	printList(head);
	return 0;
}
