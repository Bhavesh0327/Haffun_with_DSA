#include<iostream>

using namespace std;

int binarySearch(int a[] , int key , int low , int high){
	if(high>=low){
		int mid = (low+high)/2;
		if(( mid==0 || key > a[mid-1]) && (a[mid]==key)){
			return mid;
		}
		else if( key > a[mid]){
			return binarySearch(a , key , mid+1 , high);
		}
		else{
			return binarySearch(a , key , low , mid-1);
		}
	}
	return -1;
}

bool isMajority(int a[], int n, int key){
	int i;
	i = binarySearch(a , key , 0 , n-1);
	if(i==-1){
		return false;
	}
	
	if( (i+ n/2 <= n-1) && (a[i+n/2]==key)){
		return  true;
	}
	else{
		return false;
	}
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n,i,key;
		cin >> n;
		int a[n];
		for(i=0 ; i<n;i++){
			cin >> a[i];
		}
		cin >> key;
		if(isMajority(a , n, key)){
			cout << "Yes! the element is in majority in the array\n";
		}
		else{
			cout << "No! the element is not in majority in the array\n";
		}
	}
	return  0;	
}
