// C++ program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 #include <iostream>
using namespace std;
// a structure to represent a weighted edge in graph
struct Edge
{
    long long int src, dest;
    long  long int weight;
};
 
// a structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    long long int V, E;
 
    // graph is represented as an array of edges. Since the graph is
    // undirected, the edge from src to dest is also edge from dest
    // to src. Both are counted as 1 edge here.
    struct Edge* edge;
};
 
// Creates a graph with V vertices and E edges
struct Graph* createGraph(long long int V, long long int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
 
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
 
    return graph;
}
 
// A structure to represent a subset for union-find
struct subset
{
    long long int parent;
    long long int rank;
};
 
// A utility function to find set of an element i
// (uses path compression technique)
long long int find(struct subset subsets[], long long int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
 
    return subsets[i].parent;
}
 
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(struct subset subsets[], long long int x, long long int y)
{
    long long int xroot = find(subsets, x);
    long long int yroot = find(subsets, y);
 
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
 
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}
 
// Compare two edges according to their weights.
// Used in qsort() for sorting an array of edges
int myComp(const void* a, const void* b)
{
    struct Edge* a1 = (struct Edge*)a;
    struct Edge* b1 = (struct Edge*)b;
    return a1->weight > b1->weight;
}
 
// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
    long long int V = graph->V;
    struct Edge result[V];  // Tnis will store the resultant MST
    long long int e = 0;  // An index variable, used for result[]
    long long int i = 0;  // An index variable, used for sorted edges
 
    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
 
    // Allocate memory for creating V ssubsets
    struct subset *subsets =
        (struct subset*) malloc( V * sizeof(struct subset) );
 
    // Create V subsets with single elements
    for (long long int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
 
    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];
 
        long long int x = find(subsets, next_edge.src);
        long long int y = find(subsets, next_edge.dest);
 
        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }
 
    // prlong long int the contents of result[] to display the built MST
    //prlong long intf("Following are the edges in the constructed MST\n");
    long  long int count=0;
    for (i = 0; i < e; ++i)
        count+=result[i].weight;
    cout << count << endl;
    return;
}
 
// Driver program to test above functions
int main()
{
    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
    long long int V ;  // Number of vertices in graph
    long long int E; cin >> V>>E; // Number of edges in graph
    struct Graph* graph = createGraph(V, E);
    for(long long int i=0;i<E;i++){
        cin >> graph->edge[i].src ;
        cin >> graph->edge[i].dest ;
        cin >> graph->edge[i].weight ;
    }
    long long int start;cin >> start;
 
    KruskalMST(graph);
 
    return 0;
}

