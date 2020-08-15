#include<iostream>
#include<bits/stdc++.h>
#define r 1000
using namespace std;

//This one is basically binary search

int first(int arr[], int low, int high)  
{  
    if(high >= low){  
        int mid = low + (high - low)/2;  
      
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)  
            return mid;  
        
        else if (arr[mid] == 0)  
            return first(arr, (mid + 1), high);    
        else
            return first(arr, low, (mid -1));  
    }  
    return -1;  
}

int row(int a[r][r], int n, int m){
    int i, index;
    int max_row_index = 0;
    int max = first(a[0],0,n-1);
    for(i=1;i<n;i++){
        if(max!=-1 && a[i][m- max-1]==1){
            index = first(a[i],0,m-max);
            if(index!=-1 && m-index >max){
                max = m-index;
                max_row_index = i;
            }
        }
        else{
            max = first(a[i], 0 , m-1);
        }
    }
    return max_row_index;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,m,j;
        cin >> n >> m;
        int a[n][m];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin >> a[i][j];
            }
        }
        cout << row(a, n, m) << endl;
    }
    return 0;
}