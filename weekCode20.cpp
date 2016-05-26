/*
***************************************************************************************************************
 
                          Author : SHUBHAM MATTA
						  HACKERRANK HANDLE: voidcoder
                          SPOJ Handle: shubhammatta
                          Codeforces Handle: ironman1
 
**************************************************************************************************************
*/
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
#include <utility>
//#include <ctime>
//#include <memory.h>
//#include <assert.h>
#include <stdlib.h>
#include <cmath>
#include <limits.h>
#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define FOR(i,start,end) for(size_t i=start;i<end;i++)
#define rFOR(i,end,start) for(size_t i=end,i>=start;i--)
#define MOD 1000000007
#define line cout<<endl
#define ll long long int
#define LD long double
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mp make_pair
#define memory(x,y) memset(x,y,sizeof(x))
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)
#define ii pair<ll,ll>
#define F first
#define S second

using namespace std;
#include <sstream>

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

ll powerwithmodulus(ll base, ll exponent,ll modulus)
{
    ll result = 1;
    base%=modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

// int gcd(int a, int b)
// {
//     while(b) b ^= a ^= b ^= a %= b;
//     return a;
// }

// long long sum(long long N){
//     if(N/10==0) return N*(N+1)/2;
//     int i=0;
//     long long n=N;
//     while(n/10!=0){
//         i++;
//         n/=10;
//     }
//     int p=pow(10,i);
//     return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + sum(N%p));
// }
void printArray(int arr[] , int n){
	FOR(i,0,n) cout << arr[i] << " " ;
	line;
}
/**********************************************************************************************************/
/**********************************************************************************************************/
/**********************************************************************************************************/
/**********************************************************************************************************/

int n,m,k;

class shop{
public:
    int num;
    int * arr;
    shop(){
        arr = new int[k];
        for(int i=0;i<k;i++)
            arr[i]=0;
    }
};

class Edge{
public:
    int to,weight;
    Edge(int x,int y){
        to =x;
        weight= y;
    }
};

class Graph
{
public:
    int V;    // No. of vertices
    vector<Edge> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w,int weit); // to add an edge to graph
    int EdgeExist(int i,int j){
        for(int m=0;m<adj[i].size();m++){
            if(adj[i][m].to==j){ //cout << adj[i][m].weight << " weight " << i << " to " << m << endl; 
            return adj[i][m].weight;}
        };
        //cout << " neg" << endl;
        return -1;
    }
    void DFS(int start);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<Edge>[V];
}
 
void Graph::addEdge(int fr,int to , int weight)
{
    Edge x(to,weight);
    adj[fr].push_back(x); // Add w to v’s list.
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
 
void prims(Graph g , int start ,int vertices , int edges , int dist[]){
    
    int * visited = new int[vertices];
    int * mst = new int[vertices];
    
    for(int i=0;i<vertices;i++) {visited[i] = -1;mst[i]=0;}
    visited[start] = 0;
    dist[start]=0;
    vector<Edge>::iterator i;
    int e=1;
    while(e<vertices){
        int point = keyval(mst,dist,vertices);
        if(point==-1) break;
        mst[point]=1;
        for(int i=0;i<vertices;i++){
            int k=g.EdgeExist(point,i);
           // cout << "distance between edge " << i << " and  "  << point << " " <<k  << endl;
            //cout << point << " to " << i << " "<< k << endl;
            if(!mst[i] && k>=0 && k+dist[point]<dist[i]){
                //cout << point << " to  " << i << endl;
                //if(dist[i]!=INT_MAX)
                dist[i] = k+dist[point];
               // cout << dist[i] << " " << i <<" " << point <<endl;
            }
        }
        e++;
    }
    long long int count=0;
    for(int j=0;j<vertices;j++){
        if(dist[j]==INT_MAX)
          cout << -1 << " ";
        else if(dist[j]!=0)
         cout << dist[j] << " "; 
        
    }cout << endl;
}

void Graph::DFS(int s)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    int *dist = new int[V];
    for(int i=0;i<V;i++) dist[i] = INT_MAX;
    // Create a stack for DFS
    stack<int> stack;
    dist[s]=0;
    // Mark the current node as visited and push it
    visited[s] = true;
    stack.push(s);

    // 'i' will be used to get all adjacent vertices
    // of a vertex
    vector<Edge>::iterator i;

    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        cout << s << " ";
        stack.pop();

        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then mark it
        // visited and push it to the stack
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[(*i).to])
            {
                cout << " going ot " << (*i).to << endl;
                dist[(*i).to] = (*i).weight + dist[s];
                visited[(*i).to] = true;
                stack.push((*i).to);
            }
        }
    }
    cout << dist[n-1] <<  " end" << endl;
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //freopen("route.in","r",stdin);
    //freopen("route.out","w",stdout);
    //freopen("F:/in.txt", "r", stdin);
    //freopen("F:/output.txt", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n >> m >> k;
    int tmp,x,y,z,w;
    std::vector<shop> sp(n);
    FOR(i,0,n){
        sp[i].num = i;
        cin >> x;
        while(x--){
            cin >> y;
            sp[i].arr[y-1]=1;
        }
    }
    Graph g(n);
    int fr,to,weight;
    for(int i=0;i<m;i++){
        cin >> fr >> to >> weight;
        g.addEdge(fr-1,to-1,weight);
        g.addEdge(to-1,fr-1,weight);
    }
    int * dist = new int[n];
    for(int i=0;i<n;i++)
        dist[i]=INT_MAX;
    prims(g,0,n,m,dist);
    g.DFS(0);
    return 0;
}



