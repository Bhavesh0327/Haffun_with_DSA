#include<bits/stdc++.h>
using namespace  std;

#define V 100
#define INF 1e7

void print(int arr[][V], int v){
    int i,j;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void floydWarshall(int graph[][V], int v){
    int dist[v][v], i,j,k;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            dist[i][j]= graph[i][j];
        }
    }
    for(k=0;k<v;k++){
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    print(dist,v);
}

int main(){
    int t ;
    cin >> t;
    while(t--){
        int v;
        cin >> v;
        int graph[v][v];
        int i,j;
        for(i=0;i<v;i++){
            for(j=0;j<v;j++){
                cin >> graph[i][j];
            }
        }
        floydWarshall(graph,v);
    }
    return 0; 
}


