#include <bits/stdc++.h> 
using namespace std; 

class LRUCache { 
	list<int> dq; 

	unordered_map<int, list<int>::iterator> ma; 
	int csize; // maximum capacity of cache 

public: 
	LRUCache(int); 
	void refer(int); 
	void display(); 
}; 

LRUCache::LRUCache(int n){ 
	csize = n; 
} 

void LRUCache::refer(int x) {
	if (ma.find(x) == ma.end()) { 
		if (dq.size() == csize) { 
			// delete least recently used element 
			int last = dq.back(); 
			// Pops the last elmeent 
			dq.pop_back(); 
			// Erase the last 
			ma.erase(last); 
		} 
	} 

	else
		dq.erase(ma[x]); 

	dq.push_front(x); 
	ma[x] = dq.begin(); 
} 

void LRUCache::display() { 
    for (auto it = dq.begin(); it != dq.end(); 
		it++) 
		cout << (*it) << " "; 

	cout << endl; 
} 

int main(){ 
	LRUCache ca(4); 

	ca.refer(1); 
	ca.refer(2); 
	ca.refer(3); 
	ca.refer(1); 
	ca.refer(4); 
	ca.refer(5); 
	ca.display(); 

	return 0; 
} 
