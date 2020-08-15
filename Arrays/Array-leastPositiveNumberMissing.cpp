#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int segregate(int a[], int n){
    int i,j=0;
    for(i=0;i<n;i++){
        if(a[i]<=0){
            swap(&a[i], &a[j]);
            j++;
        }
    }
    return j;
}

int missing(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        if(abs(a[i])-1 <n && a[abs(a[i]) -1] >0){
            a[abs(a[i])-1] = -a[abs(a[i])-1];
        }
    }
    for(i=0;i<n;i++){
        if(a[i]>0){
            return i+1;
        }
    }
    return n+1;
}

int findMissing(int a[], int n){
    int shift = segregate(a , n);
    return missing(a+shift, n-shift);
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
        cout << findMissing(a, n) << endl;
    }
    return 0;
}