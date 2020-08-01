#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void permutations(string s, int l , int r, vector<string>& v){
    if(l==r){
        v.push_back(s);
    }
    else{
            for(int i=l;i<=r;++i){
            swap(s[l],s[i]);
            permutations(s,l+1,r,v);
            swap(s[l],s[i]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<string> v;
        permutations(s,0,n-1,v);
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}