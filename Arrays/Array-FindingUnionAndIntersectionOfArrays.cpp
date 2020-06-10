#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

void display(ll a[] , ll n){
	cout << "n = " << n << endl;
	for(ll i=0;i<n;i++){
		cout << a[i] << " " ;
	}
	cout << endl;
}
/*
for unsorted arrays
1. either sort both arrays first and repeat this method
2. copy elements of first array into union and check elements in 2nd to add in union or no
3. start elements in smaller array, if they repeat in 2nd array copy in intersection.
*/
void unionArray(ll a[],ll b[],ll n ,ll m){
	ll x[n+m];
	ll i,j,k;
	i=j=k=0;
	while(i<n && j<m){
		if(a[i]<b[j]){
			x[k++] = a[i++];
		}
		else if(b[j]<a[i]){
			x[k++] = b[j++];
		}
		else if(b[j]==a[i]){
			x[k++] = b[j++];
			i++;
		}
	}
	if(i>=n){
		while(j<m){
			x[k++] = b[j++];
		}
	}
	else if(j>=m){
		while(i<n){
			x[k++] = a[i++];
		}
	}
	display(x,k);
}

void intersectionArray(ll a[], ll b[], ll n , ll m){
	ll y[n+m];
	ll i=0,j=0,k=0;
	while(i<n && j<m){
		if(a[i] < b[j]){
			i++;
		}
		else if(a[i]>b[j]){
			j++;
		}
		else if(a[i]==b[j]){
			y[k++] = b[j++];
			i++;
		}
	}
	display(y,k);
}


int main(){
	ll n,m;
	cin >> n>>m;
	ll a[n],b[m];
	for(ll i =0;i<n;i++){
		cin >> a[i];
	}
	for(ll i=0;i<m;i++){
		cin >> b[i];
	}
	unionArray(a,b,n,m);
	intersectionArray(a,b,n,m);

	return 0;
}

