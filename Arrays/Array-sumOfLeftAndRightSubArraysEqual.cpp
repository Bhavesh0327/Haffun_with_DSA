#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int subArraySums(int a[], int n){
    int j,i,right=0,left=0;
    for(i=1;i<n;i++){
        right+=a[i];
    }
    for(i=0,j=1;j<n;j++,i++){
        right -=a[j];
        left+=a[i];
        if(left==right){
            return i+1;
        }
    }
    return -1;
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
        cout << subArraySums(a,n) << endl;
    }
    return 0;
}