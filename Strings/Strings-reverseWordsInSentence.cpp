#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

/******************************************************************
 
 *This method stores the indices before and after you get spaces and then just print the substrings

******************************************************************/

void reverseWords1(string s){
    vector<int> v;
    int i;
    v.push_back(0);
    for(i=0;i<s.size();i++){
        if(s[i]==' '){
            v.push_back(i-1);
            v.push_back(i+1);
        }
    }
    v.push_back(s.size()-1);
    for(i=v.size()-2;i>=2;i-=2){
        cout << s.substr(v[i],v[i+1]-v[i]+1) << " ";
    }
    cout << s.substr(0, v[1]-v[0]+1) << endl;
}

/******************************************************************

 * Here we reverse every word first and then reverse the string in total

******************************************************************/

void reverseWords2(string s){
    int start,end;
    start = 0;
    for(end=0;end<s.length();end++){
        if(s[end]==' '){
            reverse(s.begin()+start,s.begin()+end);
            start = end+1;
        }
    }
    reverse(s.begin()+start, s.end());
    reverse(s.begin(),s.end());
    cout << s << endl;
}

int main(){
    string s;
    s = "Hi there you good boy" ;
    reverseWords1(s);
    reverseWords2(s);
    return 0;
}