#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;cin >> t;
    ///cout << log2(1000000) << endl;
    while(t--){
        long long unsigned int a,b;
        cin >> a >> b;
        int k = log2(a);
        long long unsigned int p = pow(2,k);
        if(p>=a && 2*p<=b){
            cout << 0 << endl;
        }
        else{
           // long long int m = a&b;
            cout << a << endl;
        }
        
    }
    return 0;
}

