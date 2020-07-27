#include<iostream>
#include<cstring>
#include<string>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int lis(int arr[],int n){
    int i,j,temp[n];
    int mx;
    mx=0;
    temp[0]=arr[0];
    if(n==1){
        return arr[0];
    }
    for(i=1;i<n;i++){
        temp[i] = arr[i];
        for(j=0;j<i;j++){
            if(arr[j]<arr[i] && temp[i]< temp[j]+arr[i]){
                temp[i] =arr[i] + temp[j];
            }
        }
    }
    sort(temp, temp+n);
    return temp[n-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << lis(arr, n) << endl;
    }
    return 0;
}