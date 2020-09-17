#include<iostream>
#include<cstring>
#include<string>
#include<climits>

using namespace std;

int rodCut(int n , int arr[]){
    int val[n+1];
    val[0] = 0;
    int i,j,mx;
    for(i=1;i<=n;i++){
        mx = INT_MIN;
        for(j=0;j<i;j++){
            mx =  max(mx , arr[j]+val[i-j-1]);
        }
        val[i] = mx;
    }
    return val[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int length;
        cin >> length;
        int price[length];
        for(int i=0;i<length;i++){
            cin >> price[i];
        }
        cout << rodCut(length , price) << endl;
    }
    return 0;
}