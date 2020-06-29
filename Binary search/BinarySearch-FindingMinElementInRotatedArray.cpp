#include<iostream>

using namespace std;

int minElement(int a[] , int l , int r){
    int ans;
    int mid;
    mid = (l+r)/2;
    if(a[mid]<a[mid-1] && a[mid+1] > a[mid]){
        return a[mid];
    }
    else if(a[mid] < a[r]){
        return minElement(a , 0 , mid-1);
    }
    else{
        return minElement(a , mid+1 , r);
    }
    return ans;
}

int main(){
    int n,i;
    cout << "Enter the size of the array:\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the rotated sorted array:\n";
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    cout << "The minimum element of the array is: " << minElement(a ,0 ,  n-1) << endl;
    return 0;
}