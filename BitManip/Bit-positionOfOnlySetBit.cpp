#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int isPowerOfTwo(unsigned n){ 
    return n && (!(n & (n - 1))); 
}

int setBit(unsigned int n){
    if(!isPowerOfTwo(n)){
        return -1;
    }
    return log2(n)+1;
}

int main()
{
       int t;
       cin>>t;
       while(t--){
           int n;
           cin >> n;
           cout << setBit(n) << endl;
       }
       return 0;
}