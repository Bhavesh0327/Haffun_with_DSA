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

float closestUtil(point px[], point py[], int n){
    if(n<=3){
        return bruteforce(px,n);
    }
    int mid = n/2;
    point midPoint = px[mid];
    point pyl[mid];     //Y sorted points  on the left of vertical line
    point pyr[n-mid];   //Y sorted points on the right of vertical line
    int li = 0; int ri=0;
    for(int i=0;i<n;i++){
        if(py[i].x< midPoint.x && li<mid){
            pyl[li++] = py[i];
        }
        else{
            pyr[ri++] = py[i];
        }
    }

    float dl = closestUtil(px , pyl,mid);
    float dr = closestUtil(px+mid, pyr,n-mid);
    float d = min(dl,dr);

    point strip[n];
    int j=0;
    for(int i=0;i<n;i++){
        if(abs(py[i].x - midPoint.x)<d)
            strip[j]=py[i]; j++;
    }
    return min(d, stripClosest(strip, j, d));
}

float closest(point p[], int n){
    point px[n],py[n];
    int i;
    for(i=0;i<n;i++){
        px[i]=p[i];
        py[i]=p[i];
    }
    qsort(px , n , sizeof(point), compareX);
    qsort(py, n , sizeof(point), compareY);
    return closestUtil(px, py , n);
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