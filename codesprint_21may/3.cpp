#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string s,int n){
    for(int i=n-1;i>=n/2;i--){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        if(k==0){
            for(int i=1;i<=n;i++)
                cout << i << " "; cout << endl;
        }
        else{
            if(n%k==0){
                int tmp = n;
                tmp/=k;
                if(tmp%2==0){
                    for(int i=1;i<=tmp/2;i++){
                        for(int j=1;j<=k;j++){
                            cout << j+(2*i-1)*k << " ";
                        }
                        for(int j=1;j<=k;j++){
                            cout << j+(2*i-2)*k << " ";
                        }
                    } cout << endl;
                }else{
                    cout << -1 << endl;
                }
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}

