#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int abs(int n){
    int mask = n>>31;       //assuming 32 to be the integer size in bits
    return (mask+n)^mask;
}

int main()
{
       int t;
       cin>>t;
       while(t--){
           int n;
           cin >> n;
           cout << abs(n) << endl;
       }
       return 0;
}