#include<iostream>
#include<math.h>

using namespace std;

void powerOfTwo(long long n){
    unsigned int count = 0;
    while(n){
        count += n&1;
        n>>=1;
    }
    if(count==1){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
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