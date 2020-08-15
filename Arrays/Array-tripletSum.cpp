#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void tripletSum(int a[], int n, int sum){
    int i,j;
    for(i=0;i<n;i++){
        unordered_set<int> s;
        int curr_sum = sum- a[i];
        for(j=i+1;j<n;j++){
            if(s.find(curr_sum-a[j])!=s.end()){
                cout << a[i] << " " << a[j] << " " << curr_sum - a[j] << endl;
                return ;
            }
            s.insert(a[j]);
        }
    }
    cout << 0 << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,sum;
        cin >> n >> sum;
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        tripletSum(a, n , sum) ;
    }
    return 0;
}