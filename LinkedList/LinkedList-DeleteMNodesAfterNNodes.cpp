#include<iostream>

using namespace std;

struct node{
	int data;
	struct node* next;
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

void deletemAftern(node** head, int n, int m){
	int s;
	s = size(*head);
	if(n>=s) return;
	struct node* temp, *t_prev,*x;
	temp = *head;
	t_prev = NULL;
	x = NULL;										//This node preserves the pointer to the node previous to the m nodes to be deleted
	while(n--){
		t_prev = temp;
		temp = temp->next;
	}
	while(m-- && temp!=NULL){						//deletion will stop if either m ends or the list ends 
		x = temp;
		temp = temp->next;
		t_prev->next = temp;
		delete(x);
	}
}

int main(){
	struct node* head = NULL;
	int n,m;
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
	cout << "Enter the value of n and m : ";
	cin >> n >> m;
	deletemAftern(&head, n , m);
	print(head);
}
