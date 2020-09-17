#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long diceWays(int f, int d , int s){
    int dp[d+1][s+1],i,j;
    if(d*f<=s){
        return (d*f==x);
    }
    if(d>=x){
        return (d==x);
    }
    memset(dp , 0 , sizeof(dp));
    dp[0][0]= 1;
    for(i=1;i<=d;i++){
        for(j=1;j<=s;j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            if(j-f-1>=0){
                dp[i][j] -=dp[i-1][j-f-1]; 
            }
        }
    }
    return dp[d][s];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int f,d,s;
        cin >> f >> d >> s;
        cout << diceWays(f,d,s) << endl;
    }
    return 0;
}