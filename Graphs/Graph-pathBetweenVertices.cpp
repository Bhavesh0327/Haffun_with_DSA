#include<bits/stdc++.h>

using namespace std;

void addEdge(int u, int v, vector<int> g[]){
    g[u].push_back(v);
}
bool static visited[10001];

void dfs(int u, vector<int> g[],vector<int>& ans){
    if(visited[u]==0){
        ans.push_back(u);
        visited[u] = 1;
        vector<int>::iterator v;
        for(v=g[u].begin();v!=g[u].end();++v){
            if(visited[*v]==0){
                dfs(*v, g, ans);
            }
        }
    }
}

bool path(vector<int> g[],int a, int b){
    memset(visited, 0 , sizeof(visited));
    vector<int> ans;
    dfs(a,g,ans);
    for(int i=0;i<ans.size();i++){
        if(ans[i]==b){
            return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,e,x,y,a,b;
        cin >> n >> e;
        vector<int> g[n];
        for(int i=0;i<e;i++){
            cin >> x >> y;
            addEdge(x,y,g);
        }
        vector<int> ans;
        cin >> a >> b;
        if(path(g,a,b)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    return 0;
}