#include<iostream>
#include<vector>
using namespace std;

int ceilValue(vector<int> &v, int key , int l , int r){
    while (r - l > 1) { 
        int m = l + (r - l) / 2; 
        if (v[m] >= key) 
            r = m; 
        else
            l = m; 
    }
    return r;
}

int longestSubSequence(vector<int> &a){
    int i,length;
    length = 1;
    if(a.size()==0){
        return 0;
    }
    vector<int> b(a.size() , 0) , c(a.size() , 0);
    b[0] = a[0];
    for(i=0;i<a.size();i++){
        if(b[0]>a[i]){
            b[0] = a[i];
        }
        else if(b[length-1]<a[i]){
            b[length++] = a[i];
            c = b;
        }
        else{
            b[ceilValue(b , a[i] , -1 ,length-1 )] = a[i];
        }
    }
    for(i=0;i<length;i++){
        cout << c[i] << " ";
    }
    cout << endl;
    return length;
}

int main(){
    int n,i,x;
    vector<int> a;
    cout << "Enter the size of list\n";
    cin >> n;
    cout << "You can enter the elements now:\n";
    for(i=0;i<n;i++){
        cin >> x;
        a.push_back(x);
    }
    cout << "The length of the longest increasing subsequence in the given list is: " << longestSubSequence(a) << endl;
    return 0;
}