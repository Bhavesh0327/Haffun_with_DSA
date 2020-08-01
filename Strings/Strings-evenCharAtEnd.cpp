#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void evenAtEnd(string s){
    int i,n;
    n=s.size();
    for(i=0;i<n;i++){
        if(i%2!=0){
            s.insert(s.begin()+s.size(),s[i]);
        }
    }
    for(i=1;i<=n/2;i++){
        s.erase(i,1);
    }
    cout << s << endl;
}

// void swap ( char* a, char* b )  
// {  
//     char t = *a;  
//     *a = *b;  
//     *b = t;  
// }  
  
// void reverse ( string str, int low, int high )  
// {  
//     while ( low < high )  
//     {  
//         swap( &str[low], &str[high] );  
//         ++low;  
//         --high;  
//     }  
// } 

// void cycleLeader(string s, int shift , int len){
//     int j,i;
//     char item;
//     for (i = 1; i < len; i *= 3 )  
//     {  
//         j = i;  
  
//         item = s[j + shift];  
//         do
//         {  
//             if ( j & 1 )  
//                 j = len / 2 + j / 2;  
//             else
//                 j /= 2;  
  
//             swap(&s[j + shift], &item);  
//         }  
//         while ( j != i );  
//     } 
// }

// void moveEvenToSecondHalf(string s){
//     int k,lenFirst,lenRemaining,shift;
//     lenRemaining = s.size();
//     shift = 0;
//     while(lenRemaining){
//         k=0;
//         while(pow(3,k)+1 <=lenRemaining){
//             k++;
//         }
//         lenFirst = pow(3,k-1)+1;
//         lenRemaining -= lenFirst;
//         cycleLeader( s, shift, lenFirst );  
  
//         reverse( s, shift / 2, shift - 1 );  
  
//         reverse( s, shift, shift + lenFirst / 2 - 1 );  
//         reverse( s, shift / 2, shift + lenFirst / 2 - 1 );    
//         shift += lenFirst;  
//     }
// }


int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        evenAtEnd(s);
    }
    return 0;
}