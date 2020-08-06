#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int dest, src, weight;
};
class Graph{
    public:
    int V,E;
    Edge* edge;
};

class subset{
    public:
    int parent;
    int rank;
};

Graph* createGraph(int V, int E){
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

int find(subset subsets[], int j){
    if(subsets[j].parent!=j){
        subsets[j].parent = find(subsets, subsets[j].parent);
    }
    return subsets[j].parent;
}
int myComp(const void* a, const void* b){  
    Edge* a1 = (Edge*)a;  
    Edge* b1 = (Edge*)b;  
    return a1->weight > b1->weight;  
} 
void Union(subset subsets[], int x , int y){
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
    }
    else if(subsets[yroot].rank < subsets[xroot].rank){
        subsets[yroot].parent = xroot;
    }
    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskalsMST(Graph* graph){
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
    subset *subsets = new subset[(V*sizeof(subset))];
    for(int v=0;v<V;++v){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(e<V-1 && i<graph->E){
        Edge next_edge = graph->edge[i++];
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if(x!=y){
            result[e++] = next_edge;
            Union(subsets, x , y);
        }
    }
    for(i=0;i<e;i++){
        cout << result[i].weight << " ";
    }
    cout << endl;
    return ;
}

int main(){
    int V = 4; // Number of vertices in graph  
    int E = 5; // Number of edges in graph  
    Graph* graph = createGraph(V, E);  
  
  
    // add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weight = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weight = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weight = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weight = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weight = 4;  
  
    kruskalsMST(graph);  
    return 0;
}