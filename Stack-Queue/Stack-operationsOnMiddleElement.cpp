#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct dllNode{
    int data;
    dllNode* next;
    dllNode* prev;
};

struct Stack{
    dllNode* head;
    dllNode* mid;
    int count;
};

Stack* createStack(){
    Stack* ms = new Stack();
    ms->count = 0;
    return ms;
}

void push(int x, Stack* ms){
    dllNode *newNode = new dllNode();
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = ms->head;
    ms->count++;
    if(ms->count==1){
        ms->mid = newNode;
    }
    else{
        ms->head->prev = newNode;
        if(!(ms->count&1)){
            ms->mid = ms->mid->prev;
        }
    }
    ms->head = newNode;
    
}

int pop(Stack* ms){
    int x;
    if(ms->count==0){
        return -1;
    }
    x = ms->head->data;
    dllNode* temp;
    temp  = ms->head;
    ms->head= ms->head->next;
    ms->head->prev =NULL;
    free(temp);
    ms->count--;
    if((ms->count)&1){
        ms->mid = ms->mid->next;
    }
    return x;
}

int findMiddle(Stack* ms){
    if(ms->count==0){
        return -1;
    }
    return ms->mid->data;
}

int deleteMiddle(Stack* ms){
    if(ms->count==0){
        return -1;
    }
    int t;
    if(ms->count==1){
        t = ms->head->data;
        free(ms->head);
        return t;
    }

    dllNode* temp = ms->mid;
    if(ms->mid->prev){
        ms->mid->prev->next = temp->next;
        temp->next->prev = temp->prev;
        t = temp->data;
        free(temp);
    }
    return t;
}

int main(){
    Stack *ms = createStack();
    push(11 , ms);
    push(12, ms);
    // push(1 , ms);
    push(4, ms);
    push(5 , ms);
    push(7, ms);
    cout << pop(ms) << endl;
    cout << findMiddle(ms) << endl;
    cout << deleteMiddle(ms) << endl;
    return 0;
}