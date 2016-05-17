#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <set>
#include <string.h>
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



long long int bfs(Graph g , int start ,int vertices , int edges,int val[],int exempt){
    
    int * visited = new int[vertices];
    for(int i=0;i<vertices;i++) visited[i] = -1;
    visited[start] = val[start];
    //int count =6;
    queue<int> myqueue;
    myqueue.push(start);
    set<int>::iterator i;
    int * dis = new int[vertices];
    memset(dis,-1,vertices);dis[start]=0;
    while(!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();
        for(i=g.adj[now].begin();i!=g.adj[now].end();i++){
            if(visited[*i]<0 && (*i)!=exempt){
                //cout << now << " to " << *i << endl;
                visited[*i] = val[*i];
                myqueue.push(*i);
            }
        }
        //if(g.adj[now].begin()!=g.adj[now].end())

        //count+=6;
    }
    long long int count=0;
    for(int j=0;j<vertices;j++){
        if(visited[j]!=-1){
            count+=visited[j];
        }
    }
    return count;
}

int main() {
    int n,m;
    cin >> n;
    int val[n];
    long long int tree=0;
    long long int arr[n];
    for(int i=0;i<n;i++) {cin >> val[i];tree+=val[i];}

    Graph g(n);
    int fr,to;
    for(int i=0;i<n-1;i++){
        cin >> fr >> to;
        g.addEdge(fr-1,to-1);
        g.addEdge(to-1,fr-1);
    }
    set<int>::iterator j;
    for(int i=0;i<n;i++){
        arr[i] = tree;
        //cout << i << "   for" <<endl;
        for(j=g.adj[i].begin();j!=g.adj[i].end();j++)
            arr[i] = min(arr[i],bfs(g,i,n,m,val,*j));
    }
    long long int minim=INT_MAX;
    for(int i=0;i<n;i++)
        //cout << abs(tree-2*arr[i]) << " " << i <<endl;
    {
        minim = min(minim , abs(tree-2*arr[i]));
    }
    cout << minim << endl;
    
    return 0;
}