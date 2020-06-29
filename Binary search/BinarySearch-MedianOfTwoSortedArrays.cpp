#include<iostream>
using namespace std;

void median(int a[] , int b[] , int m, int n){
    int i,j,c[m+n],k,mid,ans;
    mid = (m+n)/2;
    i = j = k = 0;
    while(i<m && j < n){
        if(a[i]<b[j]){
            c[k++] = a[i++];
        }
        else{
            c[k++] = b[j++];
        }
    }
    if(i==m){
        while(j<n){
            c[k++] = b[j++];
        }
    }
    else if(j==n){
        while(i<m){
            c[k++] = a[i++];
        }
    }
    if(mid%2==0){
        ans = c[mid-1] + c[mid];
        ans/=2;
    }
    else{
        ans = c[mid];
    }
    cout << ans << endl;
}

int main(){
    int m,n,i;
    cout << "Enter the sizes of the two arrays you want to merge\n"; 
    cin >> m >> n;
    int a[m], b[n];
    cout << "Enter the elements of the first array in sorted order:\n";
    for(i=0;i<m;i++){
        cin >> a[i];
    }
    cout << "Similarly Enter the elements of the second array in sorted order:\n";
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    median(a , b , m , n);
    return 0;
}