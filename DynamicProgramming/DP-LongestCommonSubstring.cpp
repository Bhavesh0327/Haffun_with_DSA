#include<iostream>

using namespace std;

int lcsubstr(string a, string b , int n , int m){
    int t[n+1][m+1],i,j,result;
    result = 0;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++){
            if(i==0||j==0){
                t[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                result = max(t[i][j],result);
            }
            else{
                t[i][j] = 0;
            }
        }
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string a,b;
        cin >> a ;
        cin >> b;
        cout << lcsubstr(a,b,n,m) << endl;
    }
    return 0;
}