#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void  search(string s, string p){
    int m,n;
    n = s.size();
    m = p.size();
    int i,j;
    for(i=0;i<=n-m;i++){
        for(j=0;j<m;j++){
            if(s[i+j]!=p[j]){
                break;
            }
        }
        if(j==m){
            cout << "Pattern at  index " << i << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, p;
        cin >> s >> p;
        search(s,p);
    }
    return 0;
}