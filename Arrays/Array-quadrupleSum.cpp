/***************************************************************************
 * A naive approach for this problem can be running 4 loops and finding the sum for each 
 * quadruple but that will take O(n^4). One way to optimise this method can be using 
 * Two pointer technique for the last 2 loops which will reduce the time to O(n^3).
 * To improvise it further we can actually store the sums of all pairs in the array in 
 * a temporary array, and now we need to find a sum of pairs of those sums generated
 * which will give us the required answer if we are able to confirm that both the sums
 * have no element in common which reduces the time to O(n^2Logn).
 * To reduce it even further we can use hashing technique for the same approach, instead
 * here we save the values of all the sums we get and then find the value of "sum-currentPairSum"
 * in the hash table while making sure that all the elements are different using a map 
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void quadrupleSum(int a[], int n, int sum){
    unordered_map<int, pair<int,int>> mp;
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            mp[a[i]+a[j]] = {i, j};
        }
    }
    bool flag = false;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n-1;j++){
            int x = a[i]+a[j];
            if(mp.find(sum-x)!=mp.end()){
                pair<int, int> p = mp[sum-x];
                if(p.first!=i && p.second!=j && p.first!=j && p.second!=i){
                    flag = true;
                    cout << a[i] << " " << a[j] << " " << a[p.first] << " " << a[p.second] << " $";
                }
            }
        }
    }
    if(!flag){
        cout << -1 << endl;
    }
    else{
        cout << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i,sum;
        cin >> n >> sum;
        int a[n];
        for(i=0;i<n;i++){
            cin >> a[i];
        }
        sort(a, a+n);
        quadrupleSum(a, n , sum) ;
    }
    return 0;
}