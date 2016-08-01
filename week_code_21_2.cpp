#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(const pair<int,bool> & a ,const pair<int,bool> & b){
    return a.first > b.first;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N,K;
    vector< pair<int,bool> > imp;
    //pair<int,bool> unimp;
    cin >> N >> K;
    int l=0,x,y;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        if(y==0) l+=x;
        else imp.push_back(make_pair(x,y));
    }
    sort(imp.begin(),imp.end(),cmp);
    //for(int i=0;i<imp.size();i++) cout << imp[i].first << endl;
    //cout << "sfd" << endl;
    int sz = imp.size();
    if(K>sz) K = sz;
    for(int i=0;i<K;i++) l+=imp[i].first;
    for(int i=K;i<sz;i++) l-=imp[i].first;
    cout << l << endl;
    return 0;
}