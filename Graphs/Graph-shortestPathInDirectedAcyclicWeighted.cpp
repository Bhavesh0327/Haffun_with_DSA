#include<iostream>
#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

class AdjListNode{
    int v, weight;
    public:
    AdjListNode(int _v, int _w){
        v = _v;
        weight = _w;
    }
    int getV(){
        return v;
    }
    int getWeight(){
        return weight;
    }
};
class Graph{
    int v;
    list<AdjListNode> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int>&st);
    public:
    Graph(int v);
    void addEdge(int u, int v, int weight);
    void shortestPath(int s);
};

Graph::Graph(int v){
    this->v = v;
    adj = new list<AdjListNode>[v];
}

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v, weight);
    adj[u].push_back(node);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& st){
    visited[v] = true;
    list<AdjListNode>::iterator it;
    for(it=adj[v].begin();it!=adj[v].end();it++){
        AdjListNode node = *it;
        if(visited[node.getV()]==false){
            topologicalSortUtil(node.getV(), visited, st);
        }
    }
    st.push(v);
}

void Graph::shortestPath(int s){
    stack<int> st;
    int dist[v],i;
    bool *visited = new bool[v];
    for(i=0;i<v;i++){
        visited[i] = false;
        dist[i] = INF;
    }
    dist[s] = 0;
    for(i=0;i<v;i++){
        if(visited[i]==false){
            topologicalSortUtil(i, visited, st);
        }
    }
    while(!st.empty()){
        int u = st.top();
        st.pop();
        list<AdjListNode>::iterator i;
        if(dist[u]!=INF){
            for(i=adj[u].begin();i!=adj[u].end();i++){
                if(dist[i->getV()] > dist[u]+i->getWeight()){
                    dist[i->getV()] = dist[u] + i->getWeight();
                }
            }
        }
    }
    for(i=0;i<v;i++){
        (dist[i]==INF)? cout << "INF " : cout << dist[i] << " ";
    }
    cout << endl;
}


int main(){
    Graph g(6);
    g.addEdge(0, 1, 5); 
    g.addEdge(0, 2, 3); 
    g.addEdge(1, 3, 6); 
    g.addEdge(1, 2, 2); 
    g.addEdge(2, 4, 4); 
    g.addEdge(2, 5, 2); 
    g.addEdge(2, 3, 7); 
    g.addEdge(3, 4, -1); 
    g.addEdge(4, 5, -2);
    int s = 3;
    g.shortestPath(s);
    return 0;
}