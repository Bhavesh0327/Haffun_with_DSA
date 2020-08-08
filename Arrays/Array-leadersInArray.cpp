#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void leaders(int arr[], int n){
    int max_right = arr[n-1];
    int i,temp;
    vector<int> v;
    v.push_back(max_right);
    for(i=n-2;i>=0;i--){
        if(max_right<=arr[i]){
            max_right = arr[i];
            v.push_back(max_right);
        }
    }
    for(i=v.size()-1;i>=0;i--){
        cout << v[i] << " ";
    }
    cout << endl;
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
	    leaders(arr,n);
	}
	return 0;
}