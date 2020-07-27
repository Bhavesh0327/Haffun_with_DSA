#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

int minCostPath(int n , int mat[][20]){
    int i,j;
    for(i=1;i<n;i++){
        mat[i][0] +=mat[i-1][0];
    }
    for(i=1;i<n;i++){
        mat[0][i] +=mat[0][i-1];
    }
    for(i=1;i<n;i++){
        for(j=1;j<n;j++){
            mat[i][j] += min(mat[i-1][j-1], min(mat[i][j-1], mat[i-1][j]));
        }
    }
    return mat[n-1][n-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,j;
        cin >> n;
        int mat[20][20];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin >> mat[i][j];
            }
        }
        cout << minCostPath(n,mat) << endl;
    }
    return 0;
}