#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;cin >> n;
    vector<long long int> a(n+1);
    a[0]=0;
    long long int m =0;
    for(int i=1;i<=n;i++) {cin >> a[i];m = max(m,a[i]);}
    long long int ans = -1;
    long long int d = a[1];
    for(int bot=a[1];bot<=m;bot++){
        int t = bot;
        ans =-1;
        for(int i=1;i<=n;i++){
            t = 2*t - a[i];
            if(t<0) break;
            if(i==n && t>=0) ans = bot; 
        }
        if(ans>0) {cout << ans << endl;return 0;}
    }
    cout << 0 << endl;
    return 0;
}

