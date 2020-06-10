#include<iostream>

using namespace std;

/*
This method is used for finding just one element if it's occuring odd number of times

Hash table is the best method
*/
void xormethod(int a[], int n){
	int res=0;
	int i=0;
	for(i=0;i<n;i++){
		res = res ^ a[i];
	}
	cout << "res= " << res << endl;
}
int main(){
	int n;
	cin >> n;
	int a[n],i=0,b[10000]={0};
	for(i=0;i<n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	for(i=0;i<10000;i++){
		if(b[i]%2!=0){
			cout << i << endl;
		}
	}
	xormethod(a,n);
	return 0;
}
