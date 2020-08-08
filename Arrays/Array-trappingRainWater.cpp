#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n){
    int left[n],right[n],i,temp;
    temp = INT_MIN;
    for(i=0;i<n;i++){
        temp = max(arr[i],temp);
        left[i] = temp;
    }
    temp = INT_MIN;
    for(i=n-1;i>=0;i--){
        temp = max(arr[i],temp);
        right[i] = temp;
    }
    int ans;
    ans = 0;
    for(i=0;i<n;i++){
        ans = ans+ min(left[i],right[i]) - arr[i];
    }
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int i,arr[n];
	    for(i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    cout << maxWater(arr,n) << endl;
	}
	return 0;
}