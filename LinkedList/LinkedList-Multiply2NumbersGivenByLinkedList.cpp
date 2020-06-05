#include<iostream>
#include<cmath>

using namespace std;

struct node{
	int data;
	struct node* next;
};

void push(node** head , int data){
	struct node*  temp;
	temp = new node();
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

int size(node* head){
	struct node* temp = head;
	int l = 0;
	while(temp!=NULL){
		temp = temp->next;
		l++;
	}
	return l;
}


long multiplyLL(node* head1 , node* head2 ){
	int num1 = 0  , num2 = 0;
	while(head1 || head2){
		if(head1){
			num1 = num1*10 + head1->data;
			head1 = head1->next;
		}
		if(head2){
			num2 = num2*10 + head2->data;
			head2 = head2->next;
		}
	}
	return num1*num2;
}

int main(){
	struct node* head1=NULL , *head2 = NULL ;
	int a1[] = {2,4};
	int a2[] = {9};
	for(int i=0;i<2;i++){
		push(&head1 , a1[i]);
	}
	for(int i=0;i<1;i++){
		push(&head2 , a2[i]);
	}
	cout << multiplyLL(head1 , head2) << endl;
}
