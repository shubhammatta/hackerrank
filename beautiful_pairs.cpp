#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;cin >> n;
    int arr1[n],arr2[n];
    for(int i=0;i<n;i++) cin >> arr1[i];
    for(int i=0;i<n;i++) cin >> arr2[i];
    sort(arr1,arr1+n); sort(arr2,arr2+n);
    int count=0;
    for(int i=0;i<n;i++)
        {
        if(arr1[i]==arr2[i])
            count++;
    }
    if(count!=n)
        count++;
    cout << count << endl;
    return 0;
}

