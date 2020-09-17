#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

// int eggDrop(int e, int f){
//     if(e==1){
//         return f;
//     }
//     if(f==0 || f==1){
//         return f;
//     }
//     int temp,mn = INT_MAX,i;
//     for(i=1;i<=f;i++){
//         temp = 1 + max(eggDrop(e-1,i-1) , eggDrop(e,f-i));
//         mn = min(mn, temp);
//     }
//     return mn;
// }

int eggDrop(int e, int f){
    int dp[e+1][f+1],i,j,temp,mn = INT_MAX,k;
    for(i=0;i<=e;i++){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for(i=0;i<=f;i++){
        dp[1][i] = i;
    }
    for(i=2;i<=e;i++){
        for(j=2;j<=f;j++){
            dp[i][j] =  INT_MAX;
            for(k=1;k<=j;k++){
                temp =  1 + max(dp[i-1][k-1], dp[i][j-k]);
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }
    return dp[e][f];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        cout << eggDrop(n,k) << endl;
    }
    return 0;
}