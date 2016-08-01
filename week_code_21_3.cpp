#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    bool sorted=false;
    int n;cin >> n;
    vector<int> a(n),b(n);
    vector<int> com(101,0);
    vector<long double> fact(20,1.000000);
    for(int i=1;i<20;i++) fact[i] = (double)i*fact[i-1];
    for(int i=0;i<n;i++) cin >> a[i],b[i]=a[i],com[a[i]]++;
    sort(b.begin(),b.end());
    int c=0;
    for(int i=0;i<n;i++) if(a[i]!=b[i]) c++;
    long long  tmp=1;
    for(int i=0;i<=101;i++){
        if(com[i]>1) tmp*=fact[com[i]];
    }
    if(c==0) cout << 0 << endl;
    else{
        long double ans=0;
        //cout << fact[n] <<tmp <<  endl;
        ans=(double)fact[n]/(double)tmp;
        printf("%0.6Lf\n",ans);
    }
    return 0;
}

