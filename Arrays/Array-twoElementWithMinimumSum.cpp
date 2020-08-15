#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool compare(int a, int b){
    return abs(a) < abs(b);
}

int minSum(int a[], int n){
    sort(a, a+n , compare);
    int l=0,r=n-1;
    int sum=0,min_sum=INT_MAX;
    int min_l=0,min_r=0;
    while(l<r)
    {
        sum=a[l]+a[r];
        if(abs(sum)<abs(min_sum))
        {
            min_sum=sum;
            min_l=l;
            min_r=r;
        }
        if(sum<0)
        l++;
        else
        r--;
    }
    return a[min_l]+a[min_r];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        cout << minSum(a,n) << endl;
    }
    return 0;
}