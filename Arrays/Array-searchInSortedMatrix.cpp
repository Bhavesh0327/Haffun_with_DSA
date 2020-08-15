#include<iostream>
#include<bits/stdc++.h>
#define r 100
using namespace std;

int search(int a[][r], int n, int m, int x){
    if(n==0 && m==0)    return 0;
    int smallest = a[0][0];
    int largest = a[n-1][m-1];
    if(smallest>x || largest<x){
        return 0;
    }
    int i=0,j = m-1;
    while(i<n && j>=0){
        if(a[i][j]==x){
            return 1;
        }
        if(a[i][j]>x){
            j--;
        }
        else{
            i++;
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,m,j,x;
        cin >> n >> m;
        int a[r][r];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        cin >> x;
        cout << search(a, n, m,x) << endl;
    }
    return 0;
}