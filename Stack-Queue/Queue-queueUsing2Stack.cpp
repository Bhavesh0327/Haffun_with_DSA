#include<bits/stdc++.h>
using namespace std;
class StackQueue{

    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; 

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{   
    if(s1.empty() && s2.empty()){
        return -1;
    }
    if(s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
    }
    int ans = s2.top();
    s2.pop();
    return ans;
}

int main(){
    StackQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop();
    return 0;
}