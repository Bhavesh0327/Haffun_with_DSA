#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

int maxSumUtil(int p[], int l, int m, int h){
    int sum = 0;
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;
    for(int i=m;i>=l;i--){
        sum+=p[i];
        left_sum = max(left_sum, sum);
    }
    sum=0;
    for(int i=m+1;i<=h;i++){
        sum+=p[i];
        right_sum = max(right_sum , sum);
    }
    return max(left_sum+right_sum , max(left_sum, right_sum));
}

int maxSum(int p[], int l, int h){
    if(l==h){
        return p[l];
    }
    int mid = (l+h)/2;
    return max((maxSum(p ,0 , mid),maxSum(p,mid+1,h)), maxSumUtil(p , l , mid , h));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int p[n];
        for(i=0;i<n;i++){
            cin >> p[i];
        }
        cout << maxSum(p ,0 , n-1) << endl;
    }
    return 0;
}