#include <iostream>
#include<math.h>

using namespace std;

int leftRotate(int n,unsigned int d){
    return (n<<d)|(n>>(32-d));
}
int rightRotate(int n,unsigned int d){
    return (n>>d)|(n<<(32-d));      //This 32 is the number of bits in which the number is stored
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n,d;
	    cin >> n >> d;
        cout << leftRotate(n,d) << endl << rightRotate(n,d) << endl;
	}
	return 0;
}