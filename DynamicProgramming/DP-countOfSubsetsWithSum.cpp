#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int subset(int arr[], int sum, int n){
    int dp[n+1][sum+1];
    int i,j;
    for(i=1;i<=sum;i++){
        dp[0][i]= 0;
    }
    for(i=0;i<=n;i++){
        dp[i][0]= 1;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,sum;
        cin >> n >> sum;
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << subset(arr, sum, n) << endl;
    }
    return 0;
}