#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int nextPermutation(int n){
    vector<int> v;
    while(n){
        v.push_back(n%10);
        n/=10;
    }
    int size = v.size(),i,rep,toRep= INT_MAX, pos,pos2rep;
    bool flag = true;
    for(i=0;i<size-1;i++){
        if(v[i+1]<v[i]){
            rep = v[i+1];
            pos = i+1;
            flag = false;
            break;
        }
    }
    if(flag)    return -1;
    for(i=0;i<pos;i++){
        if(v[i]>rep){
            if(v[i]<toRep){
                toRep = v[i];
                pos2rep = i;
            }
        }
    }
    swap(v[pos], v[pos2rep]);
    reverse(v.begin(),v.end());
    int ans=0;
    for(i=0;i<size;i++){
        ans*=10;
        ans+=v[i];
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long n,i;
        cin >> n ;
        cout << nextPermutation(n) << endl;
    }
    return 0;
}