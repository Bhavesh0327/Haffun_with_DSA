#include<iostream>
#include<bits/stdc++.h>
#define r 100
using namespace std;

void spiral(int a[][r], int n, int m){
    int i,k=0,l=0;
    while(k<n && l<m){
        for(i=l;i<m;i++){
            cout << a[k][i] << " ";
        }
        k++;
        for(i=k;i<n;i++){
            cout << a[i][m-1] << " ";
        }
        m--;
        if(k<n){
            for(i=m-1;i>=l;i--){
                cout << a[n-1][i] << " ";
            }
            n--;
        }
        if(l<m){
            for(i=n-1;i>=k;i--){
                cout << a[i][l] << " ";
            }
            l++;
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,m,j;
        cin >> n >> m;
        int a[r][r];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        spiral(a, n, m);
    }
    return 0;
}