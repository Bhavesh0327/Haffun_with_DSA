#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void duplicate(string s){
    int h[256]={0};
    for(int i=0;i<s.size();i++){
        h[s[i]]++;
    }
    for(int i=0;i<256;i++){
        if(h[i]>1){
            cout << char(i) << " : " << h[i] << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        duplicate(s);
    }
    return 0;
}