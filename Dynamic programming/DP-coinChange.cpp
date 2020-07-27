#include<iostream>
#include<cstring>
#include<string>

/* 
Given a value N, find the number of ways to make change for N cents, if we have 
infinite supply of each of S = { S1, S2, .. , Sm} valued coins. 
The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, 
there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4. 
For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, 
{2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
*/
using namespace std;

int coinChange(int n , int m , int val[]){
    int t[n+1][m];
    int i,j,x,y;
    
    for(i=0;i<m;i++){
        t[0][i] = 1;
    }
    for(i=1;i<=n;i++){
        for(j=0;j<m;j++){
            x = (i-val[j] >= 0) ? t[i - val[j]][j] : 0;  
            y = (j >= 1) ? t[i][j - 1] : 0;
            t[i][j] = x+y;
        }
    }
    return t[n][m-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,i;
        cin >> m;
        int val[m];
        for(i=0;i<m;i++){
            cin >> val[i];
        }
        cin >> n;
        cout << coinChange(n , m, val) << endl;
    }
    return 0;
}