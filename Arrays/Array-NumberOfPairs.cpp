
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long countUtil(long x, long b[], long m, long temp[]){
    if(x==0)  return 0;
    if(x==1)  return temp[0];
    long *idx = upper_bound(b, b+m,x);
    long ans = (b+m) - idx ;
    ans+= (temp[0]+temp[1]);
    if(x==2) ans-= (temp[3]+temp[4]);
    if(x==3) ans+= (temp[2]);
    return ans;
}

long count(long a[], long b[] ,long n, long m){
    long i,temp[5]={0};
    for(i=0;i<m;i++){
        if(b[i]<5){
            temp[b[i]]++;
        }
    }
    sort(b, b+m);
    long count = 0;
    for(i=0;i<n;i++){
        count+= countUtil(a[i],b,m,temp);
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long m,n,i;
        cin >> n >> m;
        long a[n],b[m];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        for(i=0;i<m;i++){
            cin >> b[i];
        }
        cout << count(a,b,n,m) << endl;
    }
    return 0;
}