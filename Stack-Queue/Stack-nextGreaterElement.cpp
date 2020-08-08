#include<bits/stdc++.h>

using namespace std;

void nge(long long arr[], long n) 
{ 
    stack<long long> s;
    long long arr1[n];
    for (long i = n - 1; i >= 0; i--){ 
        while (!s.empty() && s.top() <= arr[i]) 
            s.pop(); 

        if (s.empty())  
            arr1[i] = -1;          
        else 
            arr1[i] = s.top();         
  
        s.push(arr[i]); 
    } 
  
    for (int i = 0; i < n; i++) 
        cout << arr1[i] << " ";
        cout << endl; 
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        long n,i;
        cin >> n;
        long long arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        nge(arr,n);
    }
}