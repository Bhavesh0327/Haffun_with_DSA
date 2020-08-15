#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool subarray(int a[], int n){
    unordered_set<int> sumSet;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(sum==0 || sumSet.find(sum)!=sumSet.end()){
            return true;
        }
        sumSet.insert(sum);
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        if(subarray(a,n)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}