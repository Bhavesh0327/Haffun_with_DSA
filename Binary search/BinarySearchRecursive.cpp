#include<iostream>
using namespace std;

int binarySearch(int a[], int l , int h , int key){
	int mid;
	if(l>h){
		return -1;
	}
	mid = (l+h)/2;
	if(a[mid]==key){
		return mid;
	}
	else if(a[mid]<key){
		return binarySearch(a , mid+1 , h , key);
	}
	else if(a[mid]>key){
		return binarySearch(a, l , mid-1 , key);
	}
}

int main(){
	int n,i,t,x;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	cout << "How many searches?\n";
	cin >> t;
	while(t--){
		cout << "What do you want to search now? \n";
		cin >> x;
		if(binarySearch(a,0,n-1,x)==-1){
			cout << "OOps, it seems the number isn't there.\n";
		}
		else{
			cout << "Yes it's there at " << binarySearch(a,0,n-1,x)+1 << "th position. \n" ;
		}
	}
}
