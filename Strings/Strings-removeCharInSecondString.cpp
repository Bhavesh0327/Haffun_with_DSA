#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void charRemove(string a, string b){
    int h[26]={0};
    int i;
    string s;
    for(i=0;i<b.size();i++){
        h[b[i]-'a']++;
    }
    for(i=0;i<a.size();i++){
        if(!h[a[i]-'a']){
            s.insert(s.begin()+s.size(),a[i]);
        }
    }
    cout << s << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        charRemove(a,b);
    }
    return 0;
}