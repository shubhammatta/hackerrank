#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <set>
#include <limits.h>
#include <utility>
using namespace std;
class Edge{
public:
    int to;
    int weight;
    Edge();
    Edge(int a ,int b){
        to = a;
        weight = b;
    }
};

bool operator<(const Edge &a , const Edge & b){
    return a.weight < b.weight;
}

class Graph
{
public:
    int V;    // No. of vertices
    vector<Edge> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w , int weight); // function to add an edge to graph
    int EdgeExist(int i,int j){
        for(int m=0;m<adj[i].size();m++){
            if(adj[i][m].to==j){ //cout << adj[i][m].weight << " weight " << i << " to " << m << endl; 
            return adj[i][m].weight;}
        };
        //cout << " neg" << endl;
        return -1;
    }
    
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<Edge>[V];
}
 
void Graph::addEdge(int v, int w,int weight)
{
    Edge e(w , weight);
    cout << v << " " << w << " " << weight << endl;
    if(EdgeExist(v,w)==-1)
    adj[v].push_back(e); // Add w to v’s list.
    else if(EdgeExist(v,w)>weight)
    {
        for(int m=0;m<adj[v].size();m++){
            if(adj[v][m].to==w){ 
            adj[v][m].weight= weight;}
        };
    }
}

int keyval(int mst[] , int * lst,int vertices){
    int min=INT_MAX; int min_index=-1;
    for(int i=0;i<vertices;i++){
        if(!mst[i] && lst[i]<min)
            min=lst[i],min_index=i;
    }
    //cout << "Each min " << min_index << endl;
    return min_index;
}



void prims(Graph g , int start ,int vertices , int edges,int end){
    
    int * visited = new int[vertices];
    int * mst = new int[vertices];
    int * dist = new int[vertices];
    for(int i=0;i<vertices;i++) {visited[i] = -1;mst[i]=0;dist[i]=INT_MAX;}
    visited[start] = 0;
    dist[start]=0;
    vector<Edge>::iterator i;
    int e=1;
    while(e<vertices){
        int point = keyval(mst,dist,vertices);
        mst[point]=1;
        for(int i=0;i<vertices;i++){
            int k=g.EdgeExist(point,i);
           // cout << "distance between edge " << i << " and  "  << point << " " <<k  << endl;
            //cout << point << " to " << i << " "<< k << endl;
            if(!mst[i] && k>=0 && k+dist[point]<dist[i]){
                //cout << point << " to  " << i << endl;
                //if(dist[i]!=INT_MAX)
                dist[i] = k+dist[point];
                //cout << dist[i] << " " << i <<" " << point <<endl;
            }
        }
        e++;
    }
    long long int count=0;
    for(int j=0;j<vertices;j++)
    {if(dist[j]==INT_MAX)
          cout << -1 << " ";
        else if(dist[j]!=0)
         cout << dist[j] << " ";}
        cout << endl;
}

int main() {
    
    
    int n,m;
    cin >> n >> m;
    Graph g(n);
    int fr,to,weight;
    for(int i=0;i<m;i++){
        cin >> fr >> to >> weight;
        g.addEdge(fr-1,to-1,weight);
        //g.addEdge(to-1,fr-1,weight);
        //cout << fr << to << weight << endl;
    }
    int s;cin >>s ;
    // set<int>::iterator i ;
    // for(int j=0;j<n;j++){
    //     cout << j << " -> ";
    //     for(i=g.adj[j].begin();i!=g.adj[j].end();++i){
    //         cout << *i << " ";
    //     }
    //     cout << endl;
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<g.adj[i].size();j++) cout<<i << " " <<g.adj[i][j].to << " "  << g.adj[i][j].weight << endl;
    //     cout << endl; 
    // }
    
    return 0;
}