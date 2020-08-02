#include <iostream>
#include<math.h>
using namespace std;

int countSetBits(int a){
    int count =0;
    while(a>0){
        count++;
        a&=(a-1);
    }
    return count;
}

int flip(int a, int b){
    return countSetBits(a^b);
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int a,b;
	    cin >> a >> b;
        cout << flip(a,b) << endl;
	}
	return 0;
}