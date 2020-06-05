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
		cout << p->data;
		p = p->next;
	}
	cout << endl;
}

//struct node* recursiveReverseLL(node* head){
//	struct node* p,*q;
//	if( head==NULL || head->next==NULL){
//		return head;
//	}
//	//This one is to reverse the rest of the list
//	p = recursiveReverseLL(head->next);
//	//This one is to point the reversed linked list to the current head node
//	head->next->next = head;
//	//This one makes head the last node by pointing it to null
//	head->next = NULL;
//	//This returns p as the head node of the new list
//	return p;
//}

//struct node* addLL(node* head1 , node* head2){
//	int add,carry=0; // this will hold the carry for the next pair
//	struct node* x= NULL;
//	struct node* temp1 , *temp2;
//	head1 = recursiveReverseLL(head1);
//	head2 = recursiveReverseLL(head2);
//	temp1 = head1;
//	temp2 = head2;
//	while(temp1 !=NULL && temp2 !=NULL){
//		add = temp1->data+temp2->data + carry;
//		x = insert(x , add%10);
//		carry  = add/10;
//		temp1 = temp1->next;
//		temp2 = temp2->next;
//	}
//	if(temp1 ==NULL){
//		while(temp2!=NULL){									//this is just a simpler way to do it that is not allowed
//			x = insert(x ,temp2->data);
//			temp2 = temp2->next;
//		}
//	}
//	else if(temp2==NULL){
//		while(temp1!=NULL){
//			x = insert(x , temp1->data);
//			temp1 = temp1->next;
//		}
//	}
//	head1 = recursiveReverseLL(head1);
//	head2 = recursiveReverseLL(head2);
//	x = recursiveReverseLL(x);
//	return x;
//}

void push(node** head1  , int data){
	struct node* temp;
	temp = new node();
	temp->data  = data;							//This function is to push the element infront of the result linked list
	temp->next = *head1;
	*head1 = temp;
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

void swapPointer( node** a, node** b )  
{  
    node* t = *a;  								//to swap the pointers of the two linked list
    *a = *b;  
    *b = t;  
}

struct node* addSameSize(node* head1 , node* head2,int *carry){
	struct node* result;
	result = new node();
	if(head1 == NULL){
		return NULL;
	}
	
	//this will recall the function with the next nodes of each linked list along with the proper value of carry
	result->next = addSameSize(head1->next, head2->next , carry);
	int sum;
	sum = head1->data + head2->data + *carry;
	*carry = sum/10;
	sum = sum%10;
	result->data = sum;
	
	return result;
}

void addCarryToRemaining(node* head1 , node* current , node** result, int *carry){
	int sum;
	
	//In case of carry remaining after the addition of 2 linkedlist the carry is being added upto the rest of the bigger linked list
	
	if(head1!=current){
		addCarryToRemaining(head1->next, current , result , carry);
		sum = head1->data + *carry;
		*carry = sum/10;
		sum = sum%10;
		push(result , sum);
	}
}

void addLL(node* head1 , node* head2 , node** result){
	
	if(head1 == NULL){
		*result = head2;
		return;
	}
	else if(head2==NULL){
		*result = head1;
		return;
	}
	int carry = 0;
	int s1 = sizeofLL(head1);
	int s2 = sizeofLL(head2);
	int diff  = abs(s1- s2);
	if(s1==s2){
		
		//in case both the linked lists are of same size by default
		
		*result = addSameSize(head1 , head2 , &carry);
	}
	else{
		if(s1<s2){
			swapPointer(&head1 , &head2);
		}
		struct node* current = head1;
		while(diff--){
			current = current->next;
		}
		*result = addSameSize(current, head2 , &carry);
		addCarryToRemaining(head1 , current , result , &carry);
	}
	if(carry){
		
		//if there is still some carry left it will directly be pushed into the sum linked list
		
		push(result, carry);
	}
}


int main(){
	struct node *head1= NULL, *head2=NULL , *sum = NULL;
	head1 = insert(head1,2);
	head1 = insert(head1,3);
	head1 = insert(head1,5);
	head1 = insert(head1,8);
	head1 = insert(head1,1);
	head2 = insert(head2,7);
	head2 = insert(head2,9);
	head2 = insert(head2,6);
	head2 = insert(head2,9);
	addLL(head1,head2 , &sum);
	printList(head1);
	cout << "+" << endl;
	printList(head2);
	cout << "=" << endl;
	printList(sum);
	return 0;
}
