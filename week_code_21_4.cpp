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
    while(!myq.empty()){
        int now = myq.front();
        myq.pop();
        if(vis[now]) continue;
    //cout << "here to " <<  now << " with cash " << C[now] << "  starting from  " << start  <<endl;
    
        //R[C[now]]++;
        for(int i=0;i<adj[now].size();++i){
            int k = adj[now][i];
            for(int j=0;j<adj[k].size();++j){
                int l = adj[k][j];
                bool flagl = true;
                for(int m = 0;m<adj[l].size();++m) if(adj[l][m]==now) flagl=false;
                if(l!=now && flagl)
                if((C[now] + money[l])>= C[l]){
                    //vis[l] = 1;
                    myq.push(l);
                    C[l] = C[now] + money[l];
                    R[C[l]]++;
                    if(money[l]==0) R[C[l]]++;
                    //cout << " cash " << C[l] << " at  " << l << endl; 
                }
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
    //cout << ans.size() << endl;
    // for(int i=0;i<ans.size();i++){
    //     cout << ans[i].first << " " << ans[i].second << endl;
    // }
    int sz = ans.size();
    sort(ans.begin(),ans.end(),cmp);
    cout << ans[sz-1].first << " " << ans[sz-1].second << endl;
    return 0;
}