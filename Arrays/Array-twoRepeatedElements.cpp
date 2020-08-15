#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int i,n;
	    cin >> n;
	    int a[n+2],maxim=0;
	    for(i=0;i<n+2;i++){
	        cin >> a[i];
	        maxim= max(maxim, a[i]);
	    }
	    int h[maxim+1];
        memset(h, 0 , sizeof(h));
	    for(i=0;i<n+2;i++){
	        h[a[i]]++;
	        if(h[a[i]]==2){
	            cout << a[i] << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}