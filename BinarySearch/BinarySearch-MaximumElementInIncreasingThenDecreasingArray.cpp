#include<iostream>
using namespace std;

long maxElement(long a[] , long low , long high){
	long mid;
	mid = (low+high)/2;
	if(a[mid]>a[mid+1] && a[mid] > a[mid-1]){
		return mid;
	}
	else if(a[mid] > a[mid-1] && a[mid+1] > a[mid]){
		return  maxElement(a , mid+1 , high);
	}
	else{
		return maxElement(a , low , mid-1);
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long n,i;
		cin >> n;
		long a[n];
		for(i=0;i<n;i++){
			cin >> a[i];
		}
		cout << maxElement(a , 0 , n-1) << endl;
	}
	return 0;
}
