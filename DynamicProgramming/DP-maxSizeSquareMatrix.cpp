#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

//Given a binary matrix, find out the maximum size square sub-matrix with all 1s.


int maxSquare(int arr[51][51], int n , int m){
    int i,j,temp[n][m], ans=0;
    memset(temp , 0 , sizeof(temp));
    for(i=0;i<n;i++){
        temp[i][0] = arr[i][0];
    }
    for(i=0;i<m;i++){
        temp[0][i] = arr[0][i];
    }
    for(i=1;i<n;i++){
        for(j=1;j<m;j++){
            if(arr[i][j]>0){
                temp[i][j] = min(temp[i-1][j-1], min(temp[i][j-1], temp[i-1][j]))+1;
            }
            else{
                temp[i][j] = 0;
            }
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            ans = max(ans, temp[i][j]);
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,i,j;
        cin >> n >> m;
        int c[51][51];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> c[i][j];
            }
        }
        cout << maxSquare(c , n , m) << endl;
    }
    return 0;
}