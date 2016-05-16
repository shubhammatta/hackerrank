#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <set>
using namespace std;
class Graph
{
public:
    int V;    // No. of vertices
    set<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new set<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].insert(w); // Add w to v’s list.
}



void bfs(Graph g , int start ,int vertices , int edges){
    
    int * visited = new int[vertices];
    for(int i=0;i<vertices;i++) visited[i] = -1;
    visited[start] = 0;
    int count =6;
    queue<int> myqueue;
    myqueue.push(start);
    set<int>::iterator i;
    int * dis = new int[vertices];
    memset(dis,-1,vertices);dis[start]=0;
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();
        for(i=g.adj[now].begin();i!=g.adj[now].end();i++){
            if(visited[*i]<0){
                //cout << now << " to " << *i << endl;
                visited[*i] = visited[now]+6;
                myqueue.push(*i);
            }
        }
        //if(g.adj[now].begin()!=g.adj[now].end())

        //count+=6;
    }
    for(int j=0;j<vertices;j++){
        if(visited[j]!=0){
            cout << visited[j] << " ";
        }
    }cout << endl;
}

int main() {
    int t;cin>>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        Graph g(n);
        int fr,to;
        for(int i=0;i<m;i++){
            cin >> fr >> to;
            g.addEdge(fr-1,to-1);
            g.addEdge(to-1,fr-1);
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
        bfs(g,s-1,n,m);
    }
    return 0;
}