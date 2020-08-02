#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

char* removeUtil(char *str, char *last_removed){ 
    if (str[0] == '\0' || str[1] == '\0') 
        return str; 
 
    if (str[0] == str[1]){ 
        *last_removed = str[0]; 
        while (str[1] && str[0] == str[1])
            str++; 
        str++; 
        return removeUtil(str, last_removed); 
    } 
  
    char* rem_str = removeUtil(str+1, last_removed); 
  
    if (rem_str[0] && rem_str[0] == str[0]){ 
        *last_removed = str[0]; 
        return (rem_str+1); 
    } 
  
    if (rem_str[0] == '\0' && *last_removed == str[0]) 
        return rem_str; 
  
    rem_str--; 
    rem_str[0] = str[0]; 
    return rem_str;
} 
  
char *remove(char *str) 
{ 
    char last_removed = '\0'; 
    return removeUtil(str, &last_removed); 
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        char* s;
        cin >> s;
        cout << remove(s) << endl;
    }
    return 0;
}