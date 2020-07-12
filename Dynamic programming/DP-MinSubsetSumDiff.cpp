#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int minSubset(int arr[], int n){
    int i,j,sum=0,diff;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    bool dp[n+1][sum+1];
    for(i=1;i<=sum;i++){
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
    for(i=sum/2;i>=0;i--){
        if(dp[n][i]){
            diff = sum - 2*i;
            break;
        }
    }
    return diff;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << minSubset(arr, n) << endl;
    }
    return 0;
}