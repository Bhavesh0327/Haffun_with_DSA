#include<iostream>
#include<cmath>

using namespace std;

struct node{
	int data;
	struct node* next;
};

void insert(node** head, int data){
	struct node* temp;
	temp = new node();
	temp->data = data;
	if(*head==NULL){
		*head = temp;
		return;
	}
	struct node* p;
	p = *head;
	while(p->next!=NULL){
		p = p->next;
	}
	p->next = temp;
}

void printLL(node* head){
	while(head!=NULL){
		cout <<  head->data << endl;
		head = head->next;
	}
}

int sizeLL(node* x){
	int p=0;
	while(x!=NULL){
		x = x->next;
		p++;
	}
	return p;
}

void triplet(node* x , node* y , node* z, int d){
	int i,j,k;
	struct node* p, *q , *r;
	p = x;
	q  = y;
	r = z;
	while(x!=NULL){
		y = q;
		while(y!=NULL){
			z = r;
			while(z!=NULL){
				if(z->data+y->data+x->data== d){
					cout << x->data << " , " << y->data << " , " << z->data << endl;
					return;
				}
				z =z->next;
			}
			y = y->next;
		}
		x = x->next;
	}
	cout << "No Such Pair Exists\n";
}

int main(){
	struct node* head1 , *head2 , *head3;
	head1 = head2 = head3 = NULL;
	int x = 100;
	insert(&head1 , 1);
	insert(&head2 , 2);
	insert(&head1 , 3);
	insert(&head3 , 4);
	insert(&head1 , 12);
	insert(&head2 , 53);
	insert(&head1 , 65);
	insert(&head1 , 12);
	insert(&head3 , 53);
	insert(&head3 , 0);
	insert(&head2 , 54);
	insert(&head1 , 13);
	insert(&head2 , 10);
	insert(&head1 , 9);
	insert(&head2 , 19);
	insert(&head3 , 43);
	insert(&head1 , 48);
	insert(&head3 , 67);
	insert(&head2 , 69);
	insert(&head1 , 89);
	insert(&head2 , 34);
	insert(&head3 , 23);
	insert(&head1 , 28);
	triplet(head1 , head2 , head3 , x);
}
