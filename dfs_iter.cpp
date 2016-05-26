// An Iterative C++ program to do DFS traversal from
// a given source vertex. DFS(int s) traverses vertices
// reachable from s.
#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
#define MOD 1000000007
#define modulus 1
using namespace std;
#define ll long long
 
// This class represents a directed graph using adjacency
// list representation
class Graph
{
public:
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // to add an edge to graph
    void DFS(int num);  // prints all vertices in DFS manner
 
    // prints all not yet visited vertices reachable from s
    bool DFSUtil(int s, bool visited[]);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
 
// prints all not yet visited vertices reachable from s
bool Graph::DFSUtil(int s, bool visited[])
{
    // Create a stack for DFS
    stack<int> stack;
 
    // Mark the current node as visited and push it
    visited[s] = true;
    stack.push(s);
    // 'i' will be used to get all adjacent vertices
    // of a vertex
    int tmp = s;
    list<int>::iterator i;
    int depth=0;
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        //cout << s << " ";
        stack.pop();
        depth++;
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then mark it
        // visited and push it to the stack
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                stack.push(*i);
            }
            else if(depth%2==1 && (*i)==tmp){
               //cout << *i << " visited twice second time from " << s  << " depth is  " << depth  <<endl;
                return true;
            }
        }
    }
    return false;
}
 
// prints all vertices in DFS manner
void Graph::DFS(int num)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    bool tmp;
    //cout << "Scenario #" << num << ":" << endl;
    for (int i = 0; i < V; i++)
        if (!visited[i])
        {
            tmp=DFSUtil(i, visited);
            
        }
    //cout << "No suspicious bugs found!" << endl; return;
}
 
// Driver program to test methods of graph class
int main()
{
    // Let us create a disconnected graph without
    // edges 0-2 and 0-3 in above graph
    int t;cin>>t;
    int val=t;
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
        //int s;cin >>s ;
        // list<int>::iterator i ;
        // for(int j=0;j<n;j++){
        //     cout << j << " -> ";
        //     for(i=g.adj[j].begin();i!=g.adj[j].end();++i){
        //         cout << *i << " ";
        //     }
        //     cout << endl;
        // }
        g.DFS(val-t);
    }
 
    return 0;
}