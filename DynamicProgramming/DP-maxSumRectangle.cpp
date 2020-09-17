#include<iostream>
#include<limits.h>
#include<bits/stdc++.h>
using namespace std;

int kadane(int *a, int *start, int * finish, int n ){
    int sum=0, max_sum = INT_MIN, i;
    *finish = -1;
    int local_start = 0;  
    for(i=0;i<n;++i){  
        sum += a[i];  
        if (sum < 0){
            sum = 0;  
            local_start = i + 1;  
        }  
        else if (sum > max_sum){  
            max_sum = sum;  
            *start = local_start;  
            *finish = i;  
        }  
    }  
  
    if (*finish != -1)  
        return max_sum;  
  
    max_sum = a[0];  
    *start = *finish = 0;  
  
    for (i = 1; i < n; i++){  
        if (a[i] > max_sum){  
            max_sum = a[i];  
            *start = *finish = i;  
        }  
    }  
    return max_sum;  
}

int maxSum(int a[][20], int r, int c){
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
    int left, right, i, sum, start, finish, temp[r];
    for(left=0;left<c;left++){
        memset(temp , 0 , sizeof(temp));
        for(right=left;right<c;right++){
            for (i = 0; i < r; ++i)  
                temp[i] += a[i][right]; 

            sum = kadane(temp , &start, &finish, r);
            if (sum > maxSum){  
                maxSum = sum;  
                finalLeft = left;  
                finalRight = right;  
                finalTop = start;  
                finalBottom = finish;  
            }
        }
    }
    return maxSum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int r,c,i,j;
        cin >> r>>c;
        int a[20][20];
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin >> a[i][j];
            }
        }
        cout << maxSum(a,r,c) << endl;
    }
    return  0;
}