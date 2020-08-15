#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool areAll9s(int n){
    int i;
    while(n!=0){
        if(n%10!=9){
            return 0;
        }
        n/=10;
    }
    return 1;
}

int generatePalin(int n){
    int i,j,size;
    vector<int>num;
    while(n!=0){
        num.push_back(n%10);
        n/=10;
    }
    reverse(num.begin(),num.end());
    size = num.size();
    int mid = size/2;
    i = mid-1;
    bool leftSmaller = false;
    j = (size%2)? mid+1:mid;

    while(i>=0 &&num[i]==num[j]){
        i--; j++;
    }
    if(i<0 || num[i]<num[j]){
        leftSmaller = true;
    }
    while(i>=0){
        num[j] = num[i];
        i--;
        j++;
    }
    if(leftSmaller){
        i = mid-1;
        int carry = 1;
        if(size%2){
            num[mid]+=carry;
            carry = num[mid]/10;
            num[mid]%=10;
            j = mid+1;
        }
        else{
            j = mid;
        }
        while(i>=0){
            num[i]+=carry;
            carry = num[i]/10;
            num[i]%=10;
            num[j++] = num[i--];
        }
    }
    int ans=0;
    for(i=0;i<size;i++){
        ans*=10;
        ans+=num[i];
    }
    return ans;
}

int nextPalindrome(int n){
    if(areAll9s(n)){
        return n+2;
    }
    return generatePalin(n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long n,i;
        cin >> n ;
        cout << nextPalindrome(n) << endl;
    }
    return 0;
}