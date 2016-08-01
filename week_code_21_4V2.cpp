#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
vector<int> R(3500,0);
vector<bool> vis(36,0);
vector<pair<int,int> > ans;
int n,m,fr,to;
void bfs(vector<vector<int> > adj,vector<int> money,int start){
    int cash = money[start];
    vector<int> C(n+1,0);
    C[start] =  cash;
    queue<int> myq;
    myq.push(start);
    R[C[start]]++;
    std::vector<bool> CantGO(40,0);
    while(!myq.empty()){
        int now = myq.front();
        for(int i=0;i<40;i++) CantGO[i] = false;
        CantGO[now] = true;
        myq.pop();
        if(vis[now]) continue;
        for(int i=0;i<adj[now].size();++i){
            int k = adj[now][i];
            CantGO[k] = true;
        }
        for(int j=1;j<=n;j++){
            if(!CantGO[j]){
                
                    myq.push(j);
                    C[j] = max(C[j],C[now] + money[j]);
                    R[C[j]]++;
                    //cout << " cash " << C[j] << " at  " << j << endl; 
                
            }
        }
        vis[now]=1;
    }
    for(int i=n;i>=1;i--){
        //cout << C[i] << endl;
        if(R[C[i]]>0) {
            ans.push_back(make_pair(C[i],R[C[i]]));
            return;
        }
    }
}

bool cmp(const pair<int,int> & a, const pair<int,int> & b){
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
   cin >> n >> m;
    vector<vector<int> > adj(n+1);
    vector<int> money(n+1,0);
    for(int i =1;i<=n;i++) cin >> money[i];
    for(int i=0;i<m;i++){
        cin >> fr >> to;
        adj[fr].push_back(to);
        adj[to].push_back(fr);
    }
    vector<int> R(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i])
        bfs(adj,money,i);
    }
    int sz = ans.size();
    sort(ans.begin(),ans.end(),cmp);
    cout << ans[sz-1].first << " " << ans[sz-1].second << endl;
    return 0;
}