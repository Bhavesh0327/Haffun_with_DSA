#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class point{
    public:
    int x,y;
};

int compareX(const void* a, const void* b)  
{  
    point *p1 = (point *)a, *p2 = (point *)b;  
    return (p1->x - p2->x);  
}  
    
int compareY(const void* a, const void* b)  
{  
    point *p1 = (point *)a, *p2 = (point *)b;  
    return (p1->y - p2->y);  
}

float dist(point p1, point p2){
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +  (p1.y - p2.y)*(p1.y - p2.y)); 
}

float bruteforce(point p[], int n){
    float mn = FLT_MAX;
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;++j){
            mn = min(mn , dist(p[i],p[j]));
        }
    }
    return mn;
}

float stripClosest(point strip[], int n, float d){
    float min = d;
    qsort(strip, n , sizeof(point), compareY);
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n && (strip[j].y - strip[i].y) < min; ++j)  
            if (dist(strip[i],strip[j]) < min)  
                min = dist(strip[i], strip[j]);  
  
    return min;
}

float closestUtil(point p[], int n){
    if(n<=3){
        return bruteforce(p,n);
    }
    int mid = n/2;
    point midPoint = p[mid];
    float dl = closestUtil(p,mid);
    float dr = closestUtil(p+mid,n-mid);
    float d = min(dl,dr);

    point strip[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(abs(p[i].x - midPoint.x)<d)
            strip[j]=p[i]; j++;
    }
    return min(d, stripClosest(strip, j, d));
}

float closest(point p[], int n){
    qsort(p , n , sizeof(point), compareX);
    return closestUtil(p , n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        point p[n];
        for(i=0;i<n;i++){
            cin >> p[i].x >> p[i].y;
        }
        cout << closest(p , n) << endl;
    }
    return  0;
}