#include<iostream>
#include<cstring>
#include<string>
#include<climits>
#include<bits/stdc++.h>

using namespace std;

int rodCut(int n , int a[]){
    int i;
    sort(a, a+3);
    if(a[0]!=0 && n%a[0]==0){
        return  n/a[0];
    }
    int t[n+1];
    for(i=1;i<=n;i++){
        t[i] = INT_MIN;
    }
    t[0] = 0;
    for(i=1;i<=n;i++){
        if(i-a[0]>=0 && t[i]<1 + t[i-a[0]]){
            t[i] = 1 + t[i-a[0]];
        }
        if(i-a[1]>=0 && t[i]< 1+ t[i-a[1]]){
            t[i] = 1 + t[i-a[1]];
        }
        if(i-a[2]>=0 && t[i]< 1+ t[i-a[2]]){
            t[i] = 1 + t[i-a[2]];
        }
    }
    return t[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int i,length;
        int a[3];
        cin >> length;
        for(i=0;i<3;i++){
            cin >> a[i];
        }
        cout << rodCut(length , a) << endl;
    }
    return 0;
}