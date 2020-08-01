#include<iostream>

using namespace std;

void recReverse(string s){
    if(s.size()==0){
        return ;
    }
    recReverse(s.substr(1));
    cout << s[0];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        recReverse(s);
        cout << " ";
    }
    return 0;
}