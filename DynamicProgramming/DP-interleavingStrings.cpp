#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool interleave(string a, string b , string c){
    int n,m,i,j,k;
    n = a.size();
    m = b.size();
    bool dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    if((m+n)!=c.size()){
        return  false;
    }
    dp[0][0]=true;
    for(i=1;i<=m;i++){
        if(b[i-1]==c[i-1]){
            dp[0][i]= dp[0][i-1];
        }
    }
    for(i=1;i<=n;i++){
        if(a[i-1]==c[i-1]){
            dp[i][0] = dp[i-1][0];
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            k = i+j-1;
            if(c[k]==a[i-1] && c[k]!=b[j-1] ){
                dp[i][j]= dp[i-1][j];
            }
            else if(c[k]==b[j-1] && a[i-1]!=c[k]){
                dp[i][j] = dp[i][j-1];
            }
            else if(c[k]==b[j-1] && a[i-1]==c[k]){
                dp[i][j] = dp[i-1][j]|| dp[i][j-1];
            }
        }
    }
    return dp[n][m];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b,c;
        cin >> a >> b >> c;
        if(interleave(a,b,c)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}