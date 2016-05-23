#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin >> n;
    int k;cin >> k;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    if(k<n){
        int i=n;
        vector<int> ch;
        while(k>0 && i>0)
            {
            if(arr[n-i] != i){
                ch.push_back(arr[n-i]);
                cout << i << " ";k--;
            }
            else
                cout << arr[n-i] << " ";
            i--;
        }
        for(;i>0;i--){
            if(arr[n-i]>i){
                cout << ch[n-arr[n-i]] << " ";
            }
            else cout << arr[n-i] << " ";
        }
        cout << endl;
    }
    else {
        for(int i=n;i>0;i--){
            cout << i << " ";
         }cout << endl;
    }
    return 0;
}

