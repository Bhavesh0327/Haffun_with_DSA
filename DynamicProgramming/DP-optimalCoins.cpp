#include<iostream>

using namespace std;

// int optimal(int l,int r, int c[]){
//     if(l==r){
//         return c[l];
//     }
//     if(r==l+1){
//         return max(c[l], c[r]);
//     }
//     int left,right;
//     left = c[l] + min(optimal(l+2,r,c), optimal(l+1,r-1,c));
//     right = c[r] + min(optimal(l,r-2,c), optimal(l+1,r-1,c));
//     return max(left,right);
// }

int optimal(int c[],int n){
    int dp[n][n];
    int gap,i,j;
    for(gap=0;gap<n;++gap){
        for(i=0,j=gap;j<n;++i,++j){
            int x = ((i+2)<=j)?dp[i+2][j]:0;
            int y = ((i+1)<=(j-1))?dp[i+1][j-1]:0;
            int z = (i<=(j-2))?dp[i][j-2]:0;
            dp[i][j] = max(c[i] +min(y,x), c[j] +min(y,z));
        }
    }
    return dp[0][n-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int c[n];
        for(i=0;i<n;i++){
            cin >> c[i];
        }
        cout << optimal(c , n) << endl;
    }
    return 0;
}