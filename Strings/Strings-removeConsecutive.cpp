#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(string &s){
    int i;
    int n;
    n = s.size();
    for(i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            s.erase(i,1);
            removeDuplicate(s);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        removeDuplicate(s);
        cout << s << endl;
    }
    return 0;
}