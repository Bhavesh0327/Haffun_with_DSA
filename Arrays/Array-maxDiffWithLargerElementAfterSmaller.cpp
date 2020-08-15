#include<iostream>
#include<bits/stdc++.h>
#define r 1000
using namespace std;

/*****************************************************
 * one more approach other then the one here can be
 * creating an array of differences of adjancent elements
 * and then  finding the max sum array in that array
******************************************************/

int maxDiff(int a[], int n){
    int mdiff = a[1]- a[0];
    int i;
    int min_element = a[0];
    for(i=1;i<n;i++){
        mdiff = max(mdiff, a[i]-min_element);
        min_element = min(min_element,a[i]);
    }
    return mdiff;
}
// Similarly we can also keep a track of max element from the right and we will 
// get back on the same solution

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
        cout << maxDiff(a, n) << endl;
    }
    return 0;
}