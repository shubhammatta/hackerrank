#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>
#include <stdlib.h>
#include <cmath>

#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define loop(i,start,end) for(int i=start;i<end;i++)
#define MOD 1000000007
#define modulus 1
using namespace std;
#define ll long long

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    int arr[41]={0};
    arr[0]=1;
    arr[1]=1;
    arr[2]=1;
    arr[3]=1;
    arr[4]=2;
    int arr1[217289]={0};
    arr1[0] = 1;arr1[1] =1;
    for(int i=2;i<217289;i++){
    	for(int j=2*i;j<217289;j+=i){
    		arr1[j]++;
    	}
    }
    int arr2[217289] = {0};
    for(int i=1;i<217289;i++){
    	if(arr1[i]==0){
    		arr2[i] = arr2[i-1]+1;
    	}
    	else arr2[i] = arr2[i-1];
    	//cout << arr2[i] << " val " << i << endl;
    }
    for(int i=5;i<41;i++){
    	
    	arr[i] = arr[i-1] + arr[i-4];
    	//if(i%4==0) arr[i]++;
    	//cout << arr[i] << " values "<< i<< endl;
    }
    while(t>0){
        int N;
        cin >> N;
        cout << arr2[arr[N]] << endl;
        t--;
    }
    return 0;
}



