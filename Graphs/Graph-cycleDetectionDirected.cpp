#include<bits/stdc++.h>

using namespace std;

void addEdge(int u, int v, vector<int> g[]){
    g[u].push_back(v);
}

bool cyclic(int i, bool visited[] , bool recStack[], vector<int> g[]){
    if(visited[i]==false){
        visited[i]= true;
        recStack[i] = true;
        for(int j =0;j<g[i].size();j++){ 
        if(!visited[g[i][j]] &&  cyclic(g[i][j],visited,recStack,g)){
            return true;
        }
        else{
            if(recStack[g[i][j]])
            return true;
        }
    }
    }
    recStack[i] = false;
    return false;
}

bool isCyclic(vector<int> g[], int n){
    bool visited[n];
    bool recStack[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
        recStack[i]=false;
    }
    for(int i=0;i<n;i++){
        if(cyclic(i,visited,recStack,g)){
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