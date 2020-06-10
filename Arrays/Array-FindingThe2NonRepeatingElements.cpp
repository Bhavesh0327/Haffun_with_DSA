#include<iostream>
using namespace  std;

void nonRepeat(int a[] , int n){
	int b[n] = {0};
	for(int i=0;i<n;i++){
		b[a[i]]++;
	}
	for(int i=0;i<n;i++){
		if(b[i]==1){
			cout << i << endl;
		}
	}
}

int main(){
	int a[10] = {1,2,3,2,3,4,3,4,5,2};
	int n = sizeof(a)/sizeof(a[0]);
	nonRepeat(a,n);
	return 0;
}
