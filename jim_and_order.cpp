#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class burger{
public:
    int num,t,d;
};

bool operator<(const burger & a , const burger & b){
    return a.d<b.d;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;cin >> n;
    burger arr[n];
    int t1,d1;
    for(int i=0;i<n;i++){
        cin >> t1  >> d1 ;
        arr[i].num=i;
        arr[i].t = t1;
        arr[i].d = t1+d1;
    }
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        if(arr[i].d==arr[i+1].d && arr[i].num>arr[i+1].num) swap(arr[i],arr[i+1]);
    }

    for(int i=0;i<n;i++){
        cout << arr[i].num+1 << " ";
     }cout << endl;
    return 0;
}

