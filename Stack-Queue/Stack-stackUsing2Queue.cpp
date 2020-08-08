#include<iostream>
#include<queue>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


/* The method push to push element into the stack */
void QueueStack :: push(int x)
{
        q1.push(x);
}

/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
        int ans;
        ans = -1;
        if(q1.empty()){
            return ans;
        }
        while(!q1.empty()){
            int x = q1.front();
            q1.pop();
            if(q1.empty()){
                ans = x;
                break;
            }
            q2.push(x);
        }
        swap(q1,q2);
        return ans;
}

int main(){
    QueueStack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
    s.push(4); 
  
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return  0;    
}