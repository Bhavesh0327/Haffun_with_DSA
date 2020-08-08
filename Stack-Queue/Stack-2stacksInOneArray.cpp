#include<iostream>
using namespace std;

class twoStack{
    int *arr;
    int size;
    int top1, top2;
    public:
    twoStack(int n){
        size=n;
        arr = new int[n];
        top1 = -1;
        top2 = size ;
    }
    void push1(int x){
        if(top1 < top2-1){
            top1++;
            arr[top1] = x;
        }
        else{
            cout << "Stack overflow for " << x << endl;
            return;
        }
    }
    void push2(int x){
        if(top1 < top2 - 1){
            top2--;
            arr[top2] = x;
        }
        else{
            cout << "Stalk overflow for " << x << endl;
            return ;
        }
    }
    int pop1(){
        if(top1 >= 0){
            int x = arr[top1];
            top1--;
            return x;
        }
        else{
            cout << "Stack underflow\n";
            exit(1);
        }
    }
    int pop2(){
        if(top2<size){
            int x = arr[top2];
            top2++;
            return x;
        }
        else{
            cout << "Stack underflow\n";
            exit(1);
        }
    }
};

int main(){
    twoStack ts(6);
    ts.push1(1);
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7);
    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
}