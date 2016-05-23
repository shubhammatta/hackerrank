#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int q;cin >> q;
    int x,y;
    while(q--){
        cin >> x >> y;
        if(x!=y)
        {int ans = pow(arr[x-1],arr[x]);
                ans%=2;
                if(ans==0)
                    cout << "Even" << endl;
                else 
                    cout << "Odd" << endl;}
        else{
            if(arr[x]%2==0){
                cout << "Even" << endl;
            }
            else
                cout << "Odd" << endl;
        }
    }
    return 0;
}

