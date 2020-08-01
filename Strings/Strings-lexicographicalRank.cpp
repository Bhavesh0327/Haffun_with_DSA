#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0 || n==1 ){
        return  1;
    }
    return n* fact(n-1);
}

int findRight(string s, int low, int high){
    int right, i;
    right=0;
    for (i = low + 1; i <= high; ++i) 
        if (s[i] < s[low]) 
            ++right; 
  
    return right;
}

int lexRank(string s){
    int len = s.size();
    int mul = fact(len);
    int rank = 1;
    int right;
    for(int i=0;i<len;i++){
        mul /= (len-i);
        right = findRight(s, i, len-1);
        rank += right*mul;
    }
    return rank ;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << lexRank(s) << endl;
    }
    return 0;
}