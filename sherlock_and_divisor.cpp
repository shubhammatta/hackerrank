#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int Seive(int N){
    //int arr[N];
    // memset(arr,0,N);
    long long int count = 1;
    int tmp=0;
    while(N%2==0){
        N/=2;
        tmp++;
    }
    count*=(tmp);
    long long int k=N;
    for(int i=3;i<=k && N!=1;i+=2){
        if(i*i>N)i=N;
        tmp=0;
         while(N%i==0){
             N/=i;
             tmp++;
         }
        count*=(tmp+1);
    }
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    int N;
    while(t--){
        cin >> N;
        if(N%2==1){
            cout << 0 << endl;
        }
        else{
           cout << Seive(N) << endl; 
        }
    }
    return 0;
}

