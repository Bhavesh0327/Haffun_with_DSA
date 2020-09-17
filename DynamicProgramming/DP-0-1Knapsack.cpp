#include<iostream>
#include<cstring>
#include<string>

/*
This program here has both the approaches to solve this particular problem here
1. The first one is the recursive approach alongwith the memoization technique
2. Second is the tabular approach which is so called the top-down approach.
*/

using namespace std;

static int t[1001][1001] = {-1};

int knapsackRec(int val[], int wt[], int W, int n){
    if(n==0|| W==0){
        return 0;                               //This one here is using the Recursive approach to get the answer
    }
    if(t[n][W]!=-1)
        return t[n][W];
    if(wt[n-1]<=W){
        //here we return the max value by deciding to include or not to include the particular element in the knapsack
        return t[n][W] = max(val[n-1]+knapsackRec(val, wt, W-wt[n-1], n-1), knapsackRec(val, wt,W,n-1) ); 
    }
    else if(wt[n-1]>W){
        return t[n][W] = knapsackRec(val, wt, W, n-1);
    }
    return -1;
}

int knapsack(int val[], int wt[], int W, int n){
    int dp[n+1][W+1];
    int i,j;
    for(i=0;i<=W;i++){
        dp[0][i]=0;
    }
    for(j=0;j<=n;j++){
        dp[j][0]=0;
    }
    //This part checks the previous value whether you got max by including 
    //or not including the last element and then choosing to do the same with the current element
    for(i=1;i<=n;i++){
        for(j=1;j<=W;j++){
            if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int te;
    cin >> te;
    while(te--){
        memset(t, -1, sizeof(t));
        int n,i,W;
        cin >> n >> W;
        int val[n], wt[n];
        for(i=0;i<n;i++){
            cin >> val[i];
        }
        for(i=0;i<n;i++){
            cin >> wt[i];
        }
        cout << knapsack(val,wt,W,n) << endl;       //Both will give
        cout << knapsackRec(val,wt,W,n) << endl;    //The same answers here
    }
    return 0;
}