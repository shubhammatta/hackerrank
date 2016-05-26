#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int m,n,r;
    cin >> m >> n >> r;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j] ;
        }
    }
    for(int i=1;i<=min(m,n)/2;i++){
        int tmpr = m-2*i+1;
        int tmpc = n-2*i+1;
        int rot = r%(2*tmpr+ 2* tmpc);
        vector<int> X(2*(tmpr + tmpc-2));
        vector<int> cp(2*(tmpr + tmpc-2));
        int cnt=0;
        for(int j=i-1;j<n-i;j++) X[cnt++] = arr[i-1][j];
        for(int j=i-1;j<m-i;j++) X[cnt++] = arr[j][n-i];
        for(int j=n-i;j>i-1;j--) X[cnt++] = arr[m-i][j];
        for(int j=m-i;j>i-1;j--) X[cnt++] = arr[j][i-1];
        int tot=2*(tmpr+tmpc-2);
        for(int j=0;j<2*(tmpr+tmpc-2);j++){
            cp[j] = X[(j+rot)%tot];
        }
        cnt=0;
        for(int j=i-1;j<n-i;j++) arr[i-1][j] = cp[cnt++];
        for(int j=i-1;j<m-i;j++) arr[j][n-i] = cp[cnt++];
        for(int j=n-i;j>i-1;j--) arr[m-i][j] = cp[cnt++];
        for(int j=m-i;j>i-1;j--) arr[j][i-1] = cp[cnt++];
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cout << arr[i][j] <<" ";
        cout<< endl;
    }
    return 0;
}

