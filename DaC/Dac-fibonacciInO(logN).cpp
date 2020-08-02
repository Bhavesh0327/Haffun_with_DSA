#include<iostream>

using namespace std;

void multiply(int F[2][2], int M[2][2]){
    int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] + F[0][1] * M[1][1]; 
    int z = F[1][0] * M[0][0] + F[1][1] * M[1][0]; 
    int w = F[1][0] * M[0][1] + F[1][1] * M[1][1]; 
      
    F[0][0] = x; 
    F[0][1] = y; 
    F[1][0] = z; 
    F[1][1] = w; 
}

void power(int F[2][2], int n){
    if(n==0 || n==1){
        return ;
    }
    int M[2][2] = {{1,1},{1,0}};
    power(F, n/2);
    multiply(F,F);
    if(n%2!=0){
        multiply(F,M);
    }
}

int fib(int n){
    int F[2][2] = {{1,1},{1,0}};
    if(n==0){
        return n;
    }
    power(F,n-1);
    return F[0][0];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << fib(n) << endl;
    }
    return  0;
}