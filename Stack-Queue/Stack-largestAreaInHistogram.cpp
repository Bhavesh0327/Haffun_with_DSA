// C++ linear time solution for stock span problem 
#include <iostream> 
#include <stack> 
using namespace std; 

int largestArea(int hist[], int n){
    stack<int> s;
    int i;
    int max_area = 0;  
    int tp;
    int area_with_top;
    i = 0;
    while (i < n){ 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        else{ 
            tp = s.top(); 
            s.pop(); 
            area_with_top = hist[tp] * (s.empty() ? i :  i - s.top() - 1); 
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    while (s.empty() == false){ 
        tp = s.top(); 
        s.pop(); 
        area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
    return max_area; 
}

int main(){ 
    int t;
    cin >> t;
    while(t--){
        int n,i;
        cin >> n;
        int arr[n];
        for(i=0;i<n;i++){
            cin >> arr[i];
        }
        
    }

	return 0; 
} 
