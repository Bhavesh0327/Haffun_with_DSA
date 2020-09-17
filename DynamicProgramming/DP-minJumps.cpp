#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{   if(arr[0]==0){
    return -1;
}
    int* jumps = new int[n]; 
    int min; 
    jumps[n - 1] = 0; 
    for (int i = n - 2; i >= 0; i--) { 
        if (arr[i] == 0) 
            jumps[i] = INT_MAX; 
  
        else if (arr[i] >= n - i - 1) 
            jumps[i] = 1; 
  
        else { 
            min = INT_MAX; 
  
            for (int j = i + 1; j < n && j <= arr[i] + i; j++) { 
                if (min > jumps[j]) 
                    min = jumps[j]; 
            } 
  
            if (min != INT_MAX) 
                jumps[i] = min + 1; 
            else
                jumps[i] = min;
        } 
    } 
    if(jumps[0]==INT_MAX){
        return -1;
    }
    return jumps[0]; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int i,n;
        cin >> n;
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        cout << minJumps(a,n) << endl;
    }
    return 0;
}