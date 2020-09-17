#include<iostream>

using namespace std;

int lcs(string a, string b , int n , int m){
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
    return t[n][m];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        cout << a.size()+b.size()-lcs(a,b,a.size(),b.size()) << endl;
    }
    return 0;
}