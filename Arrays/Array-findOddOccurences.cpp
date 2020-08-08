#include<iostream>

using namespace std;

void solve(int a[], int n){
    int xor2,i,x,y,set_bit;
    x = y = 0;
    xor2 = a[0];
    for(i=1;i<n;i++){
        xor2 = xor2^a[i];
    }
    set_bit = xor2 & ~(xor2-1);
    for(i=0;i<n;i++){
        if(a[i]&set_bit){
            x^=a[i];
        }
        else{
            y^=a[i];
        }
    }
    if(y<x){
        int temp;
        temp = y;
        y= x;
        x = temp;
    }
    cout << x << " " << y << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        solve(a,n);
        cout << endl;
    }
    return 0;
}