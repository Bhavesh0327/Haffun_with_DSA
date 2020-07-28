#include<iostream>
#include<limits.h>
using namespace std;

int sum(int freq[], int i, int j){
    int l,ans=0;
    for(l=i;l<=j;l++){
        ans+=freq[l];
    }
    return ans;
}

int obt(int keys[], int freq[], int n){
    int cost[n][n],i,j,k,l;
    for(i=0;i<n;i++){
        cost[i][i] = freq[i];
    }
    for(i=2;i<=n;i++){
        for(j=0;j<=n-i+1;j++){
            k = i+j-1;
            cost[j][k] = INT_MAX;
            for(l=j;l<=k;l++){
                int c = ((l>j)?cost[j][l-1]:0) + ((l<k)?cost[l+1][k]:0) + sum(freq, j,k);
                cost[j][k] = min(c,cost[j][k]); 
            }
        }
    }
    
    return cost[0][n-1];
}

int main(){
    int n;
    cin >> n;
    int i,keys[n],freq[n];
    for(i=0;i<n;i++){
        cin >> keys[i];
    }
    for(i=0;i<n;i++){
        cin >> freq[i];
    }
    cout << obt(keys, freq, n) << endl;
    return 0;
}