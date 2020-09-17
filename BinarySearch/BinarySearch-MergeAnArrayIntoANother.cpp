#include<iostream>
using namespace std;


void merge(int a[] , int b[] , int m , int n){
    int i,j,k;
    i=n;
    j=0;k=0;
    while(i<m+n && j<n){
        if(a[i]<b[j]){
            a[k++] = a[i++];
        }
        else{
            a[k++] = b[j++];
        }
    }
    if(i==m+n){
        while(j<n){
            a[k++] = b[j++];
        }
    }
    else if(j==n){
        while(i<m+n){
            a[k++] = a[i++];
        }
    }
}

int main(){
    int m,n,i;
    cout << "Enter the sizes of the two arrays you want to merge\n"; 
    cin >> m >> n;
    int a[m+n] = {-1} , b[n];
    cout << "Enter the elements of the first array in sorted order:\n";
    for(i=n;i<m+n;i++){
        cin >> a[i];
    }
    cout << "Similarly Enter the elements of the second array in sorted order:\n";
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    merge(a , b , m , n);
    cout << "The merged array is:\n";
    for(i=0;i<m+n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}