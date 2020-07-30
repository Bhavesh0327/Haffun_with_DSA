#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

//Given a sequence of matrices, find the most efficient way to multiply these matrices together. 

int mcm(int a[],int n){
    int m[n][n],i,j,k,q,d;
    memset(m , 0 , sizeof(m));
    int s[n][n] ;
    memset(s , 0 , sizeof(s));
    for(i=1;i<n;i++){
        m[i][i] = 0;
    }
    for(d=2;d<n;d++){
        for(i=1;i<n-d+1;i++){
            j = i+d-1;
            m[i][j] = INT_MAX;
            for(k=i;k<=j-1;k++){
                q = m[i][k]+ m[k+1][j] + a[i-1]*a[k]*a[j];
                if(q<m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n-1];
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
        cout << mcm(arr, n) << endl;
    }
    return 0;
}