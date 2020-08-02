#include <iostream>
#include<math.h>
using namespace std;

long long reverse(long long n){
    // bool b[32]={0};
    // long long t,ans;
    // t = 1;
    // int i;
    // ans=0;
    // for(i=0;i<32;i++){
    //     b[i] = n&t;
    //     t<<=1;
    // }
    // for(i=0;i<32;i++){
    //     ans+= b[i]*pow(2,32-i-1);
    // }
    // return ans;
    unsigned int  NO_OF_BITS = sizeof(n) * 8; 
    unsigned int reverse_num = 0; 
    int i; 
    for (i = 0; i < NO_OF_BITS; i++) 
    { 
        if((n & (1 << i))) 
           reverse_num |= 1 << ((NO_OF_BITS - 1) - i);   
   } 
    return reverse_num;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    long long int n;
	    cin >> n;
	    cout << reverse(n) << endl;
	}
	return 0;
}