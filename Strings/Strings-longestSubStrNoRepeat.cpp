#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s){
    int n = s.size(); 
  
    int res = 0;
    vector<int> lastIndex(256, -1); 
  
    int i = 0; 
  
    for (int j = 0; j < n; j++) { 
        i = max(i, lastIndex[s[j]] + 1);        //This checks if the element is repeated or no automatically
        res = max(res, j - i + 1);              //Gives the result the maximum value
        lastIndex[s[j]] = j;                    //Stores the value of index of each element in the vector
    } 
    return res;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a ;
        cout << lcs(a) << endl;
    }
    return 0;
}