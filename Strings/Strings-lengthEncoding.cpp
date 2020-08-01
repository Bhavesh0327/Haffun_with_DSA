#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void lengthEncode(string s){
    int i,temp=0;
    char j;
    string a;
    a.insert(a.begin()+0,s[0]);
    j = s[0];
    for(i=0;i<s.size();i++){
        if(s[i]==j){
            temp++;
        }
        else{
            a.insert(a.begin()+a.size(),char(temp)+'0');
            a.insert(a.begin()+a.size(),s[i]);
            temp=1;
            j=s[i];
        }
    }
    cout << a << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        lengthEncode(s);
    }
    return 0;
}