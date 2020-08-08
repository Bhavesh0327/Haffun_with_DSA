#include<iostream>

using namespace std;

int solve(int arr[], int n){
    int ans = (n+1)*(n+2)/2;
    for(int i = 0;i<n;i++){
        ans-=arr[i];
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int arr[n-1];
        for(i=0;i<n-1;i++){
            cin >> arr[i];
        }
        cout << solve(arr, n-1) << endl;
    }
}