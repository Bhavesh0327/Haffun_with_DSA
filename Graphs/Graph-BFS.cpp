#include<bits/stdc++.h>

using namespace std;

void addEdge(int u, int v, vector<int> g[]){
    g[u].push_back(v);
}

vector<int> bfs(vector<int>g[] , int n){
    vector<int> ans;
    bool *visited = new bool[n];
    for(int i=0;i<n;i++){
        visited[i] = false;
    }
    list<int> q;
    int u;
    u = 2;
    visited[u] = true;
    q.push_back(u);
    vector<int>::iterator i;
    while(!q.empty()){
        u = q.front();
        ans.push_back(u);
        q.pop_front();
        for(i=g[u].begin();i!=g[u].end();++i){
            if(!visited[*i]){
                visited[*i]= true;
                q.push_back(*i);
            }
        }
    }
    return ans;
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
        vector<int> ans;
        ans = bfs(g,n);
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}