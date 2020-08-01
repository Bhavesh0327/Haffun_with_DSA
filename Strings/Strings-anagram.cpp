#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void anagram(string a, string b){
    int n,m;
    int h[26] ={0};
    n = a.size();
    m = b.size();
    if(n!=m){
        cout << "NO\n";
        return ;
    }
    int i;
    for(i=0;i<n;i++){
        h[a[i]-'a']++;
    }
    for(i=0;i<n;i++){
        if(h[b[i]-'a']==0){
            cout << "NO\n";
            return ;
        }
        else{
            h[b[i]-'a']--;
        }
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        anagram(a,b);
    }
    return 0;
}