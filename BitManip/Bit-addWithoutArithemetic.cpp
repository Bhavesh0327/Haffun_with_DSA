#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int add(int a, int b){
    int carry;
    while(b!=0){
        carry = a&b;        //If same bits of both numbers are set, we get a carry there, and gives us the carry
        a = a^b;            //Xor gives us the addition of the numbers without carry
        b = carry<<1;       
    }
    return a;
}

int main()
{
       int t;
       cin>>t;
       while(t--){
           int a,b;
           cin >> a >> b;
           cout << add(a,b) << endl;
       }
       return 0;
}