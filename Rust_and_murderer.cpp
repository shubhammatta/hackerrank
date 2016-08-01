#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;
void djikstra(int s, vector<string> adjList, int N, int m){
    bool visited[N+1];
    int dists[N+1],v;
    for(int i=1; i<=N; i++){
        visited[i] = false;
        dists[i] = INT_MAX;
    }
    dists[s] = 0;
    priority_queue<int> Q;
    Q.push(s);
    visited[s] = false;
    while(!Q.empty()){
        int ui = Q.top();
        Q.pop();
        if(visited[ui]) continue;
        visited[ui] = true;
        for(int i=1; i<=N; i++){
            if(adjList[ui][i]=='0' && i!=ui)
            {
                v = i;
                if(!visited[v] && dists[ui] + 1 < dists[v]){
                    dists[v] = dists[ui] + 1;
                    Q.push(v);
                }
            }
        }
    }
    for(int i=1;i<=N;i++){
        if(i!=s) cout << dists[i] << " ";
    }
    cout << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;cin >> t;
    while(t--)
    {int n,m;cin>>n>>m;
        string t(n+1,'0');
        //cout << t << endl;
        vector<string> adj(n+1,t);
        int fr,to;
        for(int i=0;i<m;i++){
            cin >> fr >> to;
            adj[fr][to] = '1';
            adj[to][fr] = '1';
        }
        int s;
        cin >> s;
        djikstra(s,adj,n,m);}
    
    return 0;
}

