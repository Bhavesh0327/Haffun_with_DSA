
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void rearrange(long arr[] ,long n){
    long i, max_idx = n - 1, min_idx = 0; 
  
    long max_elem = arr[n - 1] + 1; 
  
    for (i = 0; i < n; i++) { 
        if (i % 2 == 0) { 
            arr[i] += (arr[max_idx] % max_elem) * max_elem; 
            max_idx--; 
        } 
        else { 
            arr[i] += (arr[min_idx] % max_elem) * max_elem; 
            min_idx++; 
        } 
    } 
    for ( i = 0; i < n; i++){ 
        arr[i] = arr[i] / max_elem;
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long m,n,i;
        cin >> n ;
        long a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        rearrange(a,n);
    }
    return 0;
}