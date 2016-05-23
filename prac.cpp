#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;cin >>t;
    while(t--){
        int l,b;
        cin >> l >> b;
        long long int mul= l*b;
        //cout << mul << endl;
        for(int i=sqrt(mul);i>=1;i--){
            if(mul%(i*i)==0 && l%i==0 && b%i==0){
               // cout << i << " i " << endl;
                cout << mul/(i*i) << endl;break;
             }
        }
   
    }
    return 0;
}

