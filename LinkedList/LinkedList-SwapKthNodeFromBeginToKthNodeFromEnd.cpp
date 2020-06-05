#include<iostream>
#include<cmath>

using namespace std;

struct node{
	int data;
	struct node*  next;
};

void push(node** head , int data){
	struct node* temp;
	temp = new node();
	temp->data = data;
	if(*head==NULL){
		*head = temp;
		return;
	}
	temp->next = *head;
	*head = temp;
}

void print(node* head){
	while(head!=NULL){
		cout << head->data << " ";
		head=  head->next;
	}
	cout << endl;
}

int size(node* head){
	int p=0;
	while(head!=NULL){
		head=  head->next;
		p++;
	}
	return p;
}

int deletenode(node* head, int k){
	struct node* temp;
	while(--k){
		temp = head;
		head = head->next;
	}
	int p;
	p = head->data;
	temp->next = temp->next->next;
	delete(head);
	return p;
}

void swapB2E(node** head, int k){
	struct node* p, *q ,*p_prev , *q_prev,*temp;
	temp = *head;
	int n;
	n = size(temp);
	if(k>n) return;
	if(2*k-1==n) return;
	
	for(int i=1;i<k;i++){
		p_prev = temp;
		temp = temp->next;
	}
	p = temp;
	q = *head;
	q_prev = NULL;
	for(int i=1;i<n-k+1;i++){
		q_prev = q;
		q = q->next;
	}
	if(p_prev){
		p_prev->next = q;
	}
	if(q_prev){
		q_prev->next = p;
	}
	temp = p->next;
	p->next = q->next;
	q->next = temp;
	if(k==1){
		*head = q;
	}
	if(k==n){
		*head = p;
	}
}

int main(){
	struct node* head = NULL;
	int k;
	push(&head , 8);
	push(&head , 7);
	push(&head , 6);
	push(&head , 5);
	push(&head , 4);
	push(&head , 3);
	push(&head , 2);
	push(&head , 1);
	cout << "The original List is : ";
	print(head);
	cout << "Enter the value of k: ";
	cin >> k;
	swapB2E(&head , k);
	cout << "The list after Swapping is : ";
	print(head);
	return 0;
}
