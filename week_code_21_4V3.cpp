#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <bitset>
using namespace std;
vector<long long> R(3500,0);
long long n,m,fr,to;

long long valid(vector<vector<int> > adj, string s,std::vector<int> money){
    long long ans = 0;
    s = s.substr(34-n,n+1);
    for(long long i=1;i<=n;i++){
        if(s[i]=='1'){
            ans+=money[i];
            for(long long j=0;j<adj[i].size();j++){
                int chk = adj[i][j];
                if(s[chk]=='1') return -1;
            }
        }
    }
    return ans;
}

int  main() {
    /* Enter your code here. Read input from STDIN. Prlong long output to STDOUT */  
   cin >> n >> m;
    vector<vector<int> > adj(n+1);
    vector<int> money(n+1,0);
    for(long long i =1;i<=n;i++) cin >> money[i];
    for(long long i=0;i<m;i++){
        cin >> fr >> to;
        adj[fr].push_back(to);
        adj[to].push_back(fr);
    }
    long long lim = 1<<n;
    long long mask = 0;
    while(mask<lim){
        string s = bitset<35>(mask).to_string();
        long long ans = valid(adj,s,money);
        if(ans>=0) R[ans]++;
        mask+=1;
    }
    for(long long i=3484;i>=0;i--){
        if(R[i]>0){
            cout << i << " " << R[i] << endl;
            return 0;
        }
    }
    return 0;
}