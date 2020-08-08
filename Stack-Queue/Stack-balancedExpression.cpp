#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void expression(string s){
    stack<char> ms;
    int i;
    bool flag;
    flag = true;
    for(i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
            ms.push(s[i]);
        }
        else if(ms.empty()){
            flag = false;
            break;
        }
        else if(((s[i]==')' && ms.top()!='(') || (s[i]=='}' && ms.top()!='{') || (s[i]==']' && ms.top()!='['))){
            flag = false;
            break;
        }
        else{
            if(ms.empty()){
                flag = false;
                break;
            }
            else{
                ms.pop();
            }
        }
    }
    if(flag && ms.empty()){
        cout << "balanced\n";
    }
    else{
        cout << "not balanced\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        expression(s);
    }
    return 0;
}