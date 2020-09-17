#include<iostream>
using namespace std;

int binarySearch(int a[] , int key , int low , int high){
	if(high>=low){
		int mid;
		mid = (low+high)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid] > key){
			return binarySearch(a, key , low , mid-1);
		}
		else{
			return binarySearch(a , key , mid+1  , high);
		}
	}
	return -1 ;
}

int countOccurences(int a[], int key , int n){
	int i,pos,ans=0;
	pos = binarySearch(a , key , 0 , n-1 );
	if(pos==-1){
		return -1;
	}
	for(i=pos; i>=0;i--){
		if(a[i]!=key){
			break;
		}
		ans++;
	}
	for(i=pos+1; i<n;i++){
		if(a[i]!=key){
			break;
		}
		ans++;
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int i,n,key;
		cin >> n >> key;
		int a[n];
		for(i=0;i<n;i++){
			cin >> a[i];
		}
		cout << countOccurences(a , key , n) << endl;
	}
	return 0;
}
