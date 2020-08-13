#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string firstRepeat(string s){
    istringstream iss(s);
    string token;
    unordered_map<string,int> mp;
    while(getline(iss, token , ' ')){
        if(mp.find(token)!=mp.end()){
            mp[token] +=1;
        }
        else{
            mp.insert(make_pair(token,1));
        }
    }

    istringstream is2(s);
    int count,turn=0;
    while(getline(is2, token, ' ')){
        count = mp[token];
        if(count>1){
            return token;
        }
    }
    token = "";
    return token;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s,x;
        int n,i;
        s = "";
        cin >> n;
        cin >> s;
        for(i=1;i<n;i++){
            cin >> x;
            s.insert(s.begin()+s.size(), ' ');
            s.append(x);
        }
        cout << firstRepeat(s) << endl;
    }
    return 0;
}