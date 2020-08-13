#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int nextGap(int g){
    if(g<=1){
        return 0;
    }
    return (g/2) + (g%2);
}

void merge(int a[], int b[], int n, int m){
    int i,j;
    int gap = (m+n);
    for(gap= nextGap(gap); gap>0; gap= nextGap(gap)){
        for(i=0;i+gap<n;i++){
            if(a[i]> a[i+gap]){
                swap(a[i], a[i+gap]);
            }
        }
        for(j= gap>n ? gap-n :0;i<n &&j<m; i++, j++){
            if(a[i]> b[j]){
                swap(a[i],b[j]);
            }
        }
        if(j<m){
            for(j=0;j+gap<m;j++){
                if(b[j]>b[j+gap]){
                    swap(b[j],b[j+gap]);
                }
            }
        }
    }
    for(i=0;i<n;i++){
        cout << a[i] << " ";
    }
    for(j=0;j<m;j++){
        cout << b[j]<< " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n,i;
        cin >> n >> m;
        int a[n], b[m];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        for(i=0;i<m;i++){
            cin >> b[i];
        }
        merge(a,b,n,m);
    }
    return 0;
}