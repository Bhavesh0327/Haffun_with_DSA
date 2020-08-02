#include<iostream>
#include<math.h>

using namespace std;

void powerOfTwo(long long n){
    unsigned int count = 0;
    while(n){
        count += n&1;
        n>>=1;
    }
    cout << count << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        powerOfTwo(n);
    }
    return 0;
}