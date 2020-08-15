#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool pythagoreanTriplet(int a[], int n){
    int maximum = INT_MIN;
    int i,j;
    for(i=0;i<n;i++){
        maximum = max(maximum,a[i]);
    }
    int hash[maximum+1] ;
    memset(hash,0 , sizeof(hash));
    for(i=0;i<n;i++){
        hash[a[i]]++;
    }
    for(i=1;i<maximum+1;i++){
        if(hash[i]==0){
            continue;
        }
        for(j=1;j<maximum+1;j++){
            if((i==j && hash[j]==1) || hash[j]==0){
                continue;
            }
            int val = sqrt(i*i + j*j);
            if(val*val != i*i + j*j){
                continue;
            }
            if(val > maximum){
                continue;
            }
            if(hash[val]){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n ;
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        if(pythagoreanTriplet(a, n)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
    }
    return 0;
}