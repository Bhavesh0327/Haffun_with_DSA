#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int lps(string x, int n ){
    string a,b;
    a = x;
    reverse(x.begin(), x.end());
    b = x;
    int t[n+1][n+1],i,j;
    for(i=0;i<=n;i++){
        t[i][0] = 0;
    }
    for(i=0;i<=n;i++){
        t[0][i] = 0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    return t[n][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << s.size()- lps(s , s.size()) << endl;
    }
    return 0;
}