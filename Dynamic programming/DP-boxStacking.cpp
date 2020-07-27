#include<iostream>
#include<cstring>
#include<string>
#include<bits/stdc++.h>
#include<vector>
#include<limits.h>
#include<stdio.h> 
#include<stdlib.h> 

using namespace std;

// int boxStack(int h[], int w[], int d[], int n){
//     int area[3*n],ht[3*n][3],i,j,nh[3*n],nw[3*n],nd[3*n],msh[3*n];
//     unordered_map<int, int> mp;
//     j=0;
//     for(i=0;i<n;i++){
//         ht[j][0] = h[i];
//         ht[j][1] = max(w[i], d[i]);        
//         ht[j][2] = min(w[i],d[i]);          
//         area[j] = w[i]*d[i];
//         if(!(mp.find(area[j])!=mp.end())){
//             mp[area[j]]= j;
//         }
//         j++;
//         ht[j][0] = d[i];
//         ht[j][1] = max(w[i], h[i]);
//         ht[j][2] = min(w[i],h[i]);
//         area[j] = w[i]*h[i];
//         if(!(mp.find(area[j])!=mp.end())){
//             mp[area[j]]= j;
//         }
//         j++;
//         ht[j][0] = w[i];
//         ht[j][1] = max(h[i], d[i]);
//         ht[j][2] = min(h[i],d[i]);
//         area[j] = h[i]*d[i];
//         if(!(mp.find(area[j])!=mp.end())){
//             mp[area[j]]= j;
//         }
//         j++;
//     }
//     n*=3;
//     sort(area, area+n, greater<int>());
//     for(i=0;i<n;i++){
//         nh[i] = ht[mp[area[i]]][0];
//         nw[i] = ht[mp[area[i]]][1];
//         nd[i] = ht[mp[area[i]]][2];
//         // cout << nh[i] << " " << nw[i] << " " << nd[i] << endl;
//     }

//     for(i=0;i<n;i++){
//         msh[i] = nh[i];
//     }

//     for(i=1;i<n;i++){
//         for(j=0;j<i;j++){
//             if(nw[i]<nw[j] && nd[i] < nd[j] && msh[i] < msh[j]+ nh[i]){
//                 msh[i] = msh[j] + nh[i];
//             }
//         }
//     }
//     sort(msh, msh+n);
//     return msh[n-1];
// } 

struct Box 
{ 
  int h, w, d;   
}; 
  
int compare (const void *a, const void * b) 
{ 
    return ( (*(Box *)b).d * (*(Box *)b).w ) - 
           ( (*(Box *)a).d * (*(Box *)a).w ); 
} 
  

int boxStack(int h[], int w[], int d[], int n ) 
{ 
   
   Box rot[3*n]; 
   int index = 0; 
   for (int i = 0; i < n; i++) 
   { 
      // Copy the original box 
      rot[index].h = h[i]; 
      rot[index].d = max(d[i], w[i]); 
      rot[index].w = min(d[i], w[i]); 
      index++; 
  
      // First rotation of box 
      rot[index].h = w[i]; 
      rot[index].d = max(h[i], d[i]); 
      rot[index].w = min(h[i], d[i]); 
      index++; 
  
      // Second rotation of box 
      rot[index].h = d[i]; 
      rot[index].d = max(h[i], w[i]); 
      rot[index].w = min(h[i], w[i]); 
      index++; 
   } 
  
   n = 3*n; 
   qsort (rot, n, sizeof(rot[0]), compare); 
  
   int msh[n]; 
   for (int i = 0; i < n; i++ ) 
      msh[i] = rot[i].h; 
  
   for (int i = 1; i < n; i++ ) 
      for (int j = 0; j < i; j++ ) 
         if ( rot[i].w < rot[j].w && 
              rot[i].d < rot[j].d && 
              msh[i] < msh[j] + rot[i].h 
            ) 
         { 
              msh[i] = msh[j] + rot[i].h; 
         } 
  
  
   sort(msh, msh+n);
   return msh[n-1]; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int h[n],w[n],d[n];
        for(i=0;i<n;i++){
            cin >> h[i];
            cin >> w[i];
            cin >> d[i];
        }
        cout << boxStack(h,w,d,n) << endl;
    }
    return 0;
} 
