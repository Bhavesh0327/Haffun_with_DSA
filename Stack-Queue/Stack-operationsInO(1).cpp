#include <bits/stdc++.h> 
using namespace std; 

struct MyStack{ 
	stack<int> s; 
	int minEle; 
    void getMin(){ 
		if (s.empty()) 
			cout << "Stack is empty\n"; 
		else
			cout <<"Minimum Element in the stack is: "
				<< minEle << "\n"; 
	} 

	void peek(){ 
		if (s.empty()){ 
			cout << "Stack is empty "; 
			return; 
		} 

		int t = s.top(); 

		cout << "Top Most Element is: "; 
		(t < minEle)? cout << minEle: cout << t; 
	} 

	void pop(){ 
		if (s.empty()){ 
			cout << "Stack is empty\n"; 
			return; 
		} 

		cout << "Top Most Element Removed: "; 
		int t = s.top(); 
		s.pop(); 

		if (t < minEle){ 
			cout << minEle << "\n"; 
			minEle = 2*minEle - t; 
		} 

		else
			cout << t << "\n"; 
	} 
 
	void push(int x){  
		if (s.empty()){ 
			minEle = x; 
			s.push(x); 
			cout << "Number Inserted: " << x << "\n"; 
			return; 
		} 
		if (x < minEle){ 
			s.push(2*x - minEle); 
			minEle = x; 
		} 

		else
		s.push(x); 

		cout << "Number Inserted: " << x << "\n"; 
	} 
}; 

int main() 
{ 
	MyStack s; 
	s.push(3); 
	s.push(5); 
	s.getMin(); 
	s.push(2); 
	s.push(1); 
	s.getMin(); 
	s.pop(); 
	s.getMin(); 
	s.pop(); 
	s.peek(); 

	return 0; 
} 
