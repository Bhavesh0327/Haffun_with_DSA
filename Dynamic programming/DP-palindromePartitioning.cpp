#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
using namespace std;

int dp[1001][1001];

bool isPalindrome(string s, int l, int r){
    int i;
    for(i=l;i<=(l+r)/2;i++){
        if(s[i]!=s[r-i]){
            return  false;
        }
    }
    return true;
}

/*
Recursive Approach
*/

// int palindromePartition(sing s, int l , int r ){
//     if(l>=r){
//         return 0;
//     }
//     if(isPalindrome(s,l,r)==true){
//         return 0;
//     }
//     if(dp[l][r]!=-1){
//         return dp[l][r];         
//     }
//     int ans = INT_MAX;
//     int k,temp,left,right;
//     for(k=l;k<=r-1;k++){
//         if(dp[l][k]!=-1){
//             left = dp[l][k];
//         }
//         else{
//             left = palindromePartition(s,l,k);
//         }
//         if(dp[k+1][r]!=-1){
//             right = dp[k+1][r];
//         }
//         else{
//             right = palindromePartition(s,k+1,r);
//         }
//         temp = left + right+1;
//         ans = min(ans,temp); 
//     }
//     return dp[l][r]= ans;
// }

int palindromePartition(string s){
    int n = s.length(); 
  
    int C[n]; 
    bool P[n][n]; 
  
    int i, j, k, L;   
    for (i = 0; i < n; i++) { 
        P[i][i] = true; 
    } 
  
    for (L = 2; L <= n; L++) { 
        for (i = 0; i < n - L + 1; i++) { 
            j = i + L - 1; 
  
            if (L == 2) 
                P[i][j] = (s[i] == s[j]); 
            else
                P[i][j] = (s[i] == s[j]) && P[i + 1][j - 1]; 
        } 
    } 
  
    for (i = 0; i < n; i++) { 
        if (P[0][i] == true) 
            C[i] = 0; 
        else { 
            C[i] = INT_MAX; 
            for (j = 0; j < i; j++) { 
                if (P[j + 1][i] == true && 1 + C[j] < C[i]) 
                    C[i] = 1 + C[j]; 
            } 
        } 
    } 
    return C[n - 1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        // memset(dp,-1,sizeof(dp));    //This is for the recursive approach
        string s;
        cin >> s;
        cout << palindromePartition(s) << endl;
    }
    return 0;
}