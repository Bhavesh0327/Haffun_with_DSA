#include<iostream>
#include<cstring>
#include<string>

using namespace std;

bool subset(int arr[], int sum, int n){
    bool dp[n+1][sum+1];
    int i,j;
    for(i=0;i<=sum;i++){
        dp[0][i]= false;
    }
    for(i=0;i<=n;i++){
        dp[i][0]= true;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
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
        if(subset(arr, sum, n)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}