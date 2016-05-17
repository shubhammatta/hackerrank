#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;cin >> n;
    int arr[n];
    int flag[n];
    for(int i=0;i<n;i++) cin >> arr[i],flag[i]=0;
    std::vector<int> v(n);
    vector<vector<int> > val(n,v);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp = arr[i]^arr[j];
            //if(i==j ) tmp=INT_MAX;
            val[i][j] = tmp;
            val[j][i] = tmp;
        }
    }
    int minim[n],min_indexI[n] , min_indexJ[n];
    for(int i=0;i<n;i++) minim[i]=-1;
    int maxim=0;
    for(size_t i=0;i<n;i++){
        minim[i] = INT_MAX;
        for(size_t j=0;j<n;j++)
        {
            if(i!=j && flag[j]==0)
                minim[i] = min(minim[i],val[i][j]);
            min_indexI[i] = i;
            min_indexJ[i] = j;
        }
        flag[min_indexJ[i]]=1;
        //flag[]=1;
       // cout << minim[i] << endl;
        if(maxim<minim[i]) maxim = minim[i];
    }

    


    // cout << maxim << endl;
    //     for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << val[i][j] << " ";
    //     }
    //         cout << endl;
    // }
    cout << maxim << endl;
    return 0;
}

