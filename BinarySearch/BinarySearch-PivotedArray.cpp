#include<iostream>

using namespace std;


long binarySearch(long a[], long  key, long l , long h){
	int mid;
	mid = (l+h)/2;
	if(l>h){
		return -1;
	}
	if(key==a[mid]){
		return mid;
	}
	else if(key > a[mid]){
		return binarySearch(a , key , mid+1, h);
	}
	else{
		return binarySearch(a , key , l , mid-1);
	}
}

long pivot(long a[], long l , long h){
	if(h < l) return -1;
	if(h==l) return l;
	long mid;
	mid = (l+h)/2;
	if(mid < h && a[mid]> a[mid+1]){
		return mid;
	}
	if(mid > l && a[mid]< a[mid-1]){
		return mid -1;
	}
	if(a[l] > a[mid]){
		return pivot(a , l , mid-1);
	}
	return pivot(a , mid+1 , h);
}

long pivotBinSearch(long a[] , long l, long h , long key){
	long piv;
	piv = pivot(a , l,h);
	if(piv==-1){
		return binarySearch(a , key , l ,h);
	}
	if(a[piv]==key){
		return piv;
	}
	if(a[0] <= key){
		return binarySearch(a , key , 0 , piv-1);
	}
	return binarySearch(a , key, piv+1 , h);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		long int n,i,key;
		cin >> n;
		long int a[n];
		for(i=0;i<n;i++){
	    	cin >> a[i];
		}
		cin >> key;
		cout << pivotBinSearch( a, 0 ,n-1 , key) << endl;
	}
	return 0;
}
