/***********************************************************************
 * Find the 3 elements such that a[i] < a[j] < a[k] and i < j < k
***********************************************************************/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void find3Numbers(int arr[], int n){
	int max = n - 1; 
  
    int min = 0; 
    int i; 
   
    int smaller[n];
  
    smaller[0] = -1; 
    for (i = 1; i < n; i++) { 
        if (arr[i] <= arr[min]) { 
            min = i; 
            smaller[i] = -1; 
        } 
        else
            smaller[i] = min; 
    } 
  
    int greater[n];
  
    greater[n - 1] = -1; 
    for (i = n - 2; i >= 0; i--) { 
        if (arr[i] >= arr[max]) { 
            max = i; 
            greater[i] = -1; 
        } 
        else
            greater[i] = max; 
    } 
  
    for (i = 0; i < n; i++) { 
        if (smaller[i] != -1 && greater[i] != -1) { 
            cout << arr[smaller[i]] 
                 << " " << arr[i] << " "
                 << arr[greater[i]]; 
            return; 
        } 
    } 
  
    cout << "0 \n"; 
  
    return;
}

int main() {
	int t;
	cin >> t;
	while(t--){
	    int i,n;
	    cin >> n;
	    int a[n];
		for(i=0;i<n;i++){
			cin >> a[i];
		}
		find3Numbers(a,n);
	}
	return 0;
}