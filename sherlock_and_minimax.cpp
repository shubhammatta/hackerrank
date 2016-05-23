#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int n,p,q;
    cin >> n;
    long long int arr[n];
    for(size_t i=0;i<n;i++) cin >> arr[i];
    cin >> p >> q;
    sort(arr,arr+n);
    //for(size_t i=0;i<n;i++) cout << arr[i] << " " ; cout << endl;
    long long int m,tmp;
    long long int maxim= 0;
    for(int i=0;i<n-1;i++){
        tmp= (arr[i]+arr[i+1])/2;
        if(tmp>=p && tmp <= q){
            if(maxim<tmp-arr[i] && tmp-arr[i]<arr[i+1]-tmp)
                {maxim=abs(tmp-arr[i]);m = tmp;}
            else if(maxim<arr[i+1]-tmp)
                {maxim=abs(tmp-arr[i+1]);m = tmp;}
        }
    }
    int minim = INT_MAX;
    for(int i=0;i<n;i++){
        if(minim>abs(p-arr[i]))
            minim = abs(p-arr[i]);
    }
    if(maxim<=minim){
        m=p;
    }
    minim = INT_MAX;
    for(int i=0;i<n;i++){
        if(minim>abs(q-arr[i]))
            minim = abs(q-arr[i]);
    }
    if(maxim<minim){
        m=q;
    }
    cout << m << endl;
    return 0;
}

