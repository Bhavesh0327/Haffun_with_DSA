#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool keyPair(int a[], int n, int sum){
    int i,j;
    i = 0; j=n-1;
    sort(a,a+n);
    while(i<j){
        if(a[i]+a[j]==sum){
            cout << a[i] << " " << a[j] << endl;
            return true;
        }
        else if(a[i]+a[j]<sum){
            i++;
        }
        else{
            j--;
        }
    }
    return false;
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
        if(keyPair(a, n,sum)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}