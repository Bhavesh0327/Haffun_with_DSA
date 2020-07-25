#include<iostream>
#include<cstring>
#include<strings.h>

using namespace std;

void printLCS(string a, string b , int n , int m){
    int t[n+1][m+1],i,j;
    for(i=0;i<=n;i++){
        t[i][0] = 0;
    }
    for(i=0;i<=m;i++){
        t[0][i] = 0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j] , t[i][j-1]);
            }
        }
    }
    string s;
    while(i>0&&j>0){
        if(a[i-1]==b[j-1]){
            s.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(t[i-1][j]>t[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    for(i=0;i<s.size()/2;i++){
        swap(s[i],s[s.size()-i]);
    }
    cout << s << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        printLCS(a , b  , a.size(), b.size());
    }
    return 0;
}