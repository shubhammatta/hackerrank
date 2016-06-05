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
    long long int  DFS(int num,int exempt , int * x);  // prints all vertices in DFS manner
 
    // prints all not yet visited vertices reachable from s
    bool DFSUtil(int s, bool visited[],int exempt);
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
bool Graph::DFSUtil(int s, bool visited[],int exempt)
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
            if (!visited[*i] && *i!=exempt)
            {
                visited[*i] = true;
                stack.push(*i);
            }
        }
    }
    return false;
}
 
// prints all vertices in DFS manner
long long int  Graph::DFS(int start,int exempt,int val[])
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    long long int tmp=0;
    //cout << "Scenario #" << num << ":" << endl;
    //for (int i = 0; i < V; i++)
    //    if (!visited[i])
      //  {
    DFSUtil(start, visited,exempt);
    for(int i=0;i<V;i++){
        if(visited[i]){
            tmp+=val[i];
        }
    }
    return tmp;
       // }
    
}
 
// Driver program to test methods of graph class
int main()
{
    // Let us create a disconnected graph without
    // edges 0-2 and 0-3 in above graph
   int n,m;
    cin >> n;
    int val[n];
    //long long int arr[n];
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
    list<int>::iterator j;
    bool flag[n];
    for(int i=0;i<n;i++) flag[i] = false; 
    for(int i=0;i<n;i++){
        cout << i << endl;
        
        arr[i] = tree;
        flag[i] = true;
        //cout << i << "   for" <<endl;
        for(j=g.adj[i].begin();j!=g.adj[i].end();j++)
            if(!flag[*j] && *j>i)
            arr[i] = min(arr[i],g.DFS(i,*j,val));
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