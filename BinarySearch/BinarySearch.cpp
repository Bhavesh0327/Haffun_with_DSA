#include<iostream>
using namespace std;

int binarySearch(int a[], int l , int h , int key){
	int mid;
	while(l<=h){
		mid = (l+h)/2;
		if(a[mid]==key){
			return mid;
		}
		else if(a[mid]>key){
			h = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return -1;
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
