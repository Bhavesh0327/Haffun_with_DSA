#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void nonRepeat(string s){
    pair<int,int> h[256];
    for(int i=0;i<s.size();i++){
        (h[s[i]].first)++;
        h[s[i]].second = i;
    }
    int res=INT_MAX;
    for(int i=0;i<256;i++){
        if(h[i].first==1){
            res=min(res,h[i].second);
        }
    }
    cout << s[res]<< endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        nonRepeat(s);
    }
    return 0;
}