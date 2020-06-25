#include<iostream>
using namespace std;

int ceilValue(int a[], int key , int low , int high){
	if(high>=low){
		int mid;
		mid = (low+high)/2;
		if(a[mid] > key && a[mid-1] < key){
			return mid;
		}
		else if(a[mid]>key){
			return ceilValue(a , key , low , mid-1);
		}
		else{
			return  ceilValue(a , key , mid+1 , high);
		}
	}
	return -1;
}

int floorValue(int a[], int key , int low , int high){
	if(high>=low){
		int mid;
		mid = (low+high)/2;
		if(a[mid] > key && a[mid-1] < key){
			return mid-1;
		}
		else if(a[mid]>key){
			return floorValue(a , key , low , mid-1);
		}
		else{
			return  floorValue(a , key , mid+1 , high);
		}
	}
	return -1;
}

int main(){
	int n,key,i;
	cout << "Enter the size of the array\n";
	cin >> n;
	int a[n];
	cout << "Enter the elements of the array\n";
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	cout << "Enter the key you are searching the values for\n";
	cin >> key;
	cout << "Floor: " << a[floorValue(a , key , 0 , n-1)] << endl;
	cout << "Ceil: " << a[ceilValue(a, key , 0 , n-1)] << endl;
	return 0;
}
