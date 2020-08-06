#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int dest, src;
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
    graph->edge = new Edge[graph->E* sizeof(Edge)];
    return graph;
}

int find(subset subsets[], int j){
    if(subsets[j].parent!=j){
        subsets[j].parent = find(subsets, subsets[j].parent);
    }
    return subsets[j].parent;
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

int isCyclic(Graph* graph){
    int V = graph->V;
    int E = graph->E;
    subset* subsets = (subset*) malloc(V*sizeof(subset));
    for(int i=0;i<V;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    for(int i=0;i<E;i++){
        int x = find(subsets, graph->edge[i].src);
        int y = find(subsets, graph->edge[i].dest);
        if(x==y){
            return 1;
        }
        Union(subsets, x , y);
    }
    return 0;
}

int main(){
    int V = 3, E = 3;  
    Graph* graph = createGraph(V, E);  
  
    // add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
  
    // add edge 1-2  
    graph->edge[1].src = 1;  
    graph->edge[1].dest = 2;  
  
    // add edge 0-2  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 2;  
  
    if (isCyclic(graph))  
        cout<<"graph contains cycle\n";  
    else
        cout<<"graph doesn't contain cycle\n";  
    return 0;
}