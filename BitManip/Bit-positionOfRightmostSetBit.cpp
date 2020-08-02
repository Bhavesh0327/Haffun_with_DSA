#include<iostream>
#include<bits/stdc++.h>

using namespace std;

unsigned int posSetBit(int n){
    return log2(n& -n) +1;
}

int main()
{
       int t;
       cin>>t;
       while(t--){
           int n;
           cin >> n;
           cout << posSetBit(n) << endl;
       }
       return 0;
}