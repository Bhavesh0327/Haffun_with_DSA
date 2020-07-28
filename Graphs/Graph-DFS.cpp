#include<bits/stdc++.h>

using namespace std;

void addEdge(int u, int v, vector<int> g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}
bool static visited[10001];

void solve(int u, vector<int> g[],vector<int>& ans){
    if(visited[u]==0){
        ans.push_back(u);
        visited[u] = 1;
        vector<int>::iterator v;
        for(v=g[u].begin();v!=g[u].end();++v){
            if(visited[*v]==0){
                solve(*v, g, ans);
            }
        }
    }
}

vector<int> dfs(vector<int> g[],int n){
    memset(visited, 0 , sizeof(visited));
    vector<int> ans;
    solve(0,g,ans);
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
        ans = dfs(g,n);
        for(int i=0;i<ans.size();i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}