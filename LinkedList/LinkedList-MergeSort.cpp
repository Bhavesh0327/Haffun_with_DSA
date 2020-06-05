#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
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
	struct node*p;
	p = head;
	while(p!=NULL){
		cout << p->data << ", ";
		p = p->next;
	}
	cout << "\b\b " << endl;
}

int sizeofLL(node* head){
	int n=0;
	struct node* p = head;
	while(p!=NULL){								//to find out the length of the current linked list
		p = p->next;
		n++;
	}
	return n;
}

struct node* SortedMerge(node* a, node* b) 
{ 
    struct node* final;
    final = NULL;
    if(a==NULL){
    	return b;
	}
	else if(b==NULL){
		return a;
	}
	while(a!=NULL && b!=NULL){
		if(a->data<=b->data){
			final = insert(final ,a->data);
			a = a->next;
		}														//This function merges 2 sorted lists
		else{
			final = insert(final, b->data);
			b = b->next;
		}
	}
	if(a==NULL){
		while(b!=NULL){
			final = insert(final , b->data);
			b = b->next;
		}
	}
	else if(b==NULL){
		while(a!=NULL){
			final = insert(final ,a->data);
			a = a->next;
		}
	}
	return final;
}

void mergeSort(node** head, int n){
	if(*head==NULL || n==1){
		return;
	}
	struct node* first, *second, *temp,*mid;
	mid = temp = *head;
	if(n%2!=0){
		while(temp->next!=NULL){
			mid = mid->next;
			temp = temp->next->next;			//dividing a list into 2 parts depends on the size of the list
		}										//if it's odd (n+1)/2 is the mid
	}
	else{
		while(temp->next->next!=NULL){			//if it's even n/2 is mid
			mid = mid->next;
			temp = temp->next->next;
		}
	}
	first = *head;
	second = mid->next;
	mid->next=NULL;
	mergeSort(&first, sizeofLL(first));			//mergeSort the first half
	mergeSort(&second, sizeofLL(second));		//mergeSort the second half
	*head = SortedMerge(first, second);			//merge both the sorted lists and point *head to the final sorted list
}

int main(){
	struct node *head= NULL;
	head = insert(head , 1);
	head = insert(head , 12);
	head = insert(head , 26);
	head = insert(head , 54);
	head = insert(head , 2);
	head = insert(head , 9);
	head = insert(head , 87);
	head = insert(head , 67);
	head = insert(head , 23);
	head = insert(head , 65);
	head = insert(head , 3);
	cout << "The original list is : ";printList(head);
	mergeSort(&head, sizeofLL(head));
	cout << "After sorting we get : "; printList(head); 
	return 0;
}
