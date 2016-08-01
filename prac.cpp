//Author : Nitin Singh Budhwar a.k.a SinOfWrath

#define ssync ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)  // in case of using only c++ input stream and not stdio(much faster)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define fst first
#define scd second
#define pb push_back

#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip> //io manipluation
#include <climits>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef unsigned long long int ull;

int main(){
	ssync;
	int n,m;
	cin>>n>>m;
	int cost[n+1];
	cost[0]=0;
	FOR(i,1,n+1) cin>>cost[i];
	vector<ll> ed(35,0);
	int a,b;
	FOR(i,0,m){
		cin>>a>>b;
		ed[a] |= ((ll)1<<(b-1));
		ed[b] |= ((ll)1<<(a-1));
	}

	vector<pil> best[35];
	best[0].pb(pil(0,(ll)0));
	best[1].pb(pil(cost[1],ed[1]));

	int sum,maxc=cost[1],count_max=1;
	FOR(i,2,n+1){
		best[i].pb(pil(cost[i],ed[i]));
		if(maxc<cost[i]){
			maxc=cost[i];
			count_max=1;
		}
		else if(maxc==cost[i]) count_max++;
		for(int j=i-1;j>0;j--){
			FOR(k,0,best[j].size()){
				if(((ll)1<<(i-1) & best[j][k].scd)==0){
					best[i].pb(pil(best[j][k].fst+cost[i],best[j][k].scd | ed[i]));
					sum=best[j][k].fst+cost[i];
					if(maxc<sum){
						maxc=sum;
						count_max=1;
					}
					else if(maxc==sum) count_max++;
				}
			}
		}

	}
	cout << maxc << " "<<count_max<<endl;
	return 0;
}