#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void topologicalUtil(int v, bool visited[], stack<int>& st);
    public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSort(){
    stack<int> st;
    bool* visited = new bool[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            topologicalUtil(i, visited, st);
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

void Graph::topologicalUtil(int v, bool visited[], stack<int>& st){
    visited[v] = true;
    list<int>::iterator i;
    for(i=adj[v].begin(); i!=adj[v].end();i++){
        if(!visited[*i]){
            topologicalUtil(*i, visited, st);
        }
    }
    st.push(v);
}

int main(){
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    g.topologicalSort(); 
  
    return 0; 
}