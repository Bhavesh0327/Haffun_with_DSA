#include<bits/stdc++.h>
using namespace  std;

struct Edge{
    int src, dest, weight;
};

struct Graph{
    int V,E;
    struct Edge* edge;
};

struct Graph* createGraph( int V, int E){
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
};

void printArray(int dis[], int n){
    int i;
    for(i=0;i<n;i++){
        cout << dis[i] << " "; 
    }
    cout << endl;
}

void BellmanFord(Graph* graph, int src){
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int i,j;
    
    for(i=0;i<V;i++){
        dist[i] = INT_MAX;
    }
    dist[src]=0;
    int u,v,weight;
    for(i=1;i<V;i++){
        for(j=0;j<E;j++){
            u = graph->edge[j].src;
            v = graph->edge[j].dest;
            weight = graph->edge[j].weight;
            if(dist[u]!=INT_MAX && dist[u]+weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }
    for(i=0;i<V;i++){
        u = graph->edge[i].src;
        v = graph->edge[i].dest;
        weight = graph->edge[i].weight;
        if(dist[u]!=INT_MAX && dist[u]+weight < dist[v]){
            cout << 0 << endl;
            return ;
        }
    }
    cout << 1 << endl;
    return;
}

int main(){
    int t ;
    cin >> t;
    while(t--){
        int v,e,x,y,z,i;
        cin >> v >> e;
        Graph* graph = createGraph(v,e);
        for(i=0;i<e;i++){
            cin >> x >> y >> z;
            graph->edge[x].src = x;
            graph->edge[x].dest = y;
            graph->edge[x].weight = z;
        }
        BellmanFord(graph, 0);
    }
    return 0; 
}


