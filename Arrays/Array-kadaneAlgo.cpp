#include<iostream>
#include<limits.h>
using namespace std;

int kadane(int arr[], int n){
    int i;
    int max_so_far, max_ending_here;
    max_ending_here = 0;
    max_so_far = INT_MIN;
    for(i=0;i<n;i++){
        max_ending_here = max_ending_here + arr[i];
        if(max_so_far < max_ending_here){
            max_so_far = max_ending_here;
        }
        if(max_ending_here <0){
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n], i;
        for(i=0;i<n;i++){
            cin >>  arr[i];
        }
        cout << kadane(arr, n) << endl;
    }
    return 0;
}