#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void computeLPS(string p, int m, int* lps){
    int len = 0;
    lps[0] = 0;
    int i=1;
    while(i<m){
        if(p[i]==p[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=lps[i-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmp(string s, string p){
    int n,m,i,j;
    i=j=0;
    n = s.size();
    m = p.size();
    int lps[m];
    computeLPS(p , m , lps);
    while(i<n){
        if(p[j]==s[i]){
            i++;
            j++;
        }
        if(j==m){
            cout << "pattern at " << i-j << endl;
            j = lps[j-1];
        }
        else if (i < n && p[j] != s[i]){
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s, p;
        cin >> s >> p;
        kmp(s,p);
    }
    return 0;
}