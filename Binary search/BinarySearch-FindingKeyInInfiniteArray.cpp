#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int> &a , int l , int r , int key){
    int mid;
    mid = (l+r)/2;
    if(a[mid]== key ){
        return mid;
    }
    else if(a[mid] > key){
        return binarySearch(a , l , mid-1 , key);
    }
    else{
        return binarySearch(a , mid+1 , r , key);
    }
    return -1;
}

/* 
    basic idea here is to find the range of elements where we can run 
    our binary search to find the first occuerence of element one
*/
void findingOne(vector<int> &a){
    int i, ans;
    if(a[0]==1){
        cout << 0 << endl;
        return  ;
    }
    i = 1;
    while(a[i]!=1){
        i*=2;
    }
    cout << binarySearch(a , i/2 , i , 1) << endl;
} 

int main(){
    int temp,i;
    vector<int> a;
    for(i=0;i<10;i++){          // Here i took array size 10 just for reference 
        cin >> temp;
        a.push_back(temp);
    }
    findingOne(a);
    return 0;
}