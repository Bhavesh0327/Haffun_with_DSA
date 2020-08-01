#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int atoi(string s){
    int i;
    int ans;
    bool ok;
    ok = true;
    if(s[0]=='-'){
        ok = false;
    }
    ans=0;
    for(i=s.size()-1;i>0;i--){
        if(s[i]>='a'){
            return -1;
        }
        ans+=pow(10,s.size()-i-1)*(s[i]-'0');
    }
    if(ok==true){
        ans+=pow(10,s.size()-1)*(s[0]-'0');
    }
    else{
        return -1*ans;
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << atoi(s) << endl;
    }
    return 0;
}