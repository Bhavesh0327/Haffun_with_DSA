#include<iostream>

using namespace std;

long long binpow(int n, int p){
    if(p==0){
        return 1;
    }
    long long temp = binpow(n , p/2);
    if(p%2==0){
        return temp*temp;
    }
    else{
        return n*temp*temp;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,p;
        cin >> n >> p;
        cout << binpow(n,p) << endl;
    }
    return  0;
}