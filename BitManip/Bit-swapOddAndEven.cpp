#include<iostream>
#include<bits/stdc++.h>

using namespace std;

unsigned int swapBits(int n){
    unsigned int e,o;
    e = n& 0xAAAAAAAA;          //this gives a number with all even bits
    o = n& 0x55555555;          //This gives a number with all odd bits
    e>>=1;                      //right shift even digits by 1
    o<<=1;                      //left shift odd digits by 1
    return e|o;                 //combine them gives answer
}

int main()
{
       int t;
       cin>>t;
       while(t--){
           int n;
           cin >> n;
           cout << swapBits(n) << endl;
       }
       return 0;
}