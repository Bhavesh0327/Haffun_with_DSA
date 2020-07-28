#include<bits/stdc++.h>

using namespace std;

void addEdge(int u, int v, vector<int> g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}

bool cyclic(int i, bool visited[] , vector<int> g[], int parent){
    visited[i] = true;
    vector<int>::iterator x;
    for(x=g[i].begin();x!=g[i].end();++x){
        if(!visited[*x]){
            if(cyclic(*x, visited, g ,i)){
                return true;
            }
        }
        else if(*x!=parent){
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int n){
    bool visited[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    for(int i=0;i<n;i++){
        if(cyclic(i,visited,g,-1)){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,e,x,y;
        cin >> n >> e;
        vector<int> g[n];
        for(int i=0;i<e;i++){
            cin >> x >> y;
            addEdge(x,y,g);
        }
        if(isCyclic(g,n)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}