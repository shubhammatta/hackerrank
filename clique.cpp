#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int turan(int n,long long int e){
    double tmp=0;
    int r=1;
    while(e>tmp && r<n){
        tmp = ((double)(1-1/r))*e*e/2;
        //cout << r << "  r" << endl;
        r++;
    }
    if(r==n)
    r-=1;
    return r;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    while(t--){
        int n;long long int m;
        cin >> n >> m ;
        if(m!=n*(n-1)/2)
            //turan(n,m);
        cout << turan(n,m) << endl;
        else 
            cout << n << endl;
    }
    return 0;
}

