#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
long long int arr[1001][1001]={0};

void pascal(){
    for(int i=0;i<1001;i++){
        for(int j=0;j<i+1;j++){
            if(i==0 || j==0)
                arr[i][j]=1;
            else{
                arr[i][j] = (arr[i-1][j] + arr[i-1][j-1])%MOD;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin >> t;
    pascal();
    while(t--){
        int N,M;
        cin >> N >> M;
        cout << arr[M+N-1][N] << endl;
    }
    return 0;
}

