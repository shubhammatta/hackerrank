#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//someone else;s code./

#define mod 1000000007
int main() {
    ios_base::sync_with_stdio(true);
    //long long t, n, i, arr[200005], res[200005], temp, sum;
    //vector<long long int> arr(200010,0);
    string s;cin >> s;
    int n =s.size();
    // arr[0] = s[0]-'0';
    long long int fr = 1;
    long long int ans =0;
    for(int i=n-1;i>=0;i--){
        ans= (ans + fr*(s[i]-'0')*(i+1)%mod)%mod;
        fr = (fr*10 + 1)%mod;
    }
    cout << ans << endl;
    return 0;
}