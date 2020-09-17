#include<iostream>

using namespace std;
const long N = 10e7;
void printUnsorted(long a[] , long n){
	long i,j,k,max=0 , min = N;
	for(i=0;i<n-1;i++){
		if(a[i]>a[i+1]){
			break;
		}
	}
	for(j=n-1;j>0;j--){
		if(a[j]<a[j-1]){
			break;
		}
	}
	for(k=i;k<=j;k++){
		if(a[k]<min){
			min = a[k];
		}
		if(a[k]>max){
			max = a[k];
		}
	}
	for(k=i-1;k>=0;k--){
		if(a[k]>min){
			i = k;
		}
	}
	for(k=j+1;k<n;k++){
		if(a[k]<max){
			j = k;
		}
	}
	cout << i << " " << j <<  endl;
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
		printUnsorted(a , n);
	}
	return 0;
}
