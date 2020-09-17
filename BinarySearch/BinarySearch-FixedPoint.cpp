#include<iostream>
using namespace std;

int fixedPoint(int a[] , int low , int high){
	if(high>=low){
		int mid;
		mid = (low+high)/2;
		if(a[mid]==mid){
			return mid+1;
		}
		else if(a[mid] > mid){
			return fixedPoint(a , low , mid-1);
		}
		else{
			return fixedPoint(a , mid+1 , high);
		}
	}
	return -1;
}

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
		if(fixedPoint(a , 0, n-1)==-1){
			cout << "Not Found\n";
		}
		else{
			cout << fixedPoint(a ,0 , n-1) << endl;
		}
	}
	return 0;
}
