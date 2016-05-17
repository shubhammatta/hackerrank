#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n , m;
int arr[11][11]={0};
int depth;
long long int max5(long long int a,long long int b,long long int c){
    return max(a,max(b,c));
}

int invalid(long int i,long int j){
    if(i>=0 && i<m && j>=0 && j<n) return 0;
    else return 1;
}
int getvalue(long int i,long int j){
    if(i>=0 && i<m && j>=0 && j<n) return arr[i][j];
    else return 0;
}

int rec(int i,int j,int flag[][11]){
	// for(int p=0;p<m;p++){
	// 		for(int k=0;k<n;k++) cout << flag[i][j] << " ";
	// 			cout << endl;
	// 	}
    if(!invalid(i,j) && !flag[i][j] && arr[i][j]==1)
    {
		flag[i][j]=1;
		depth++;
		cout << endl;
		long long int maxim = 0;
		for(int t1=i-1;t1<i+2;t1++){
			for(int t2=j-1;t2<j+2;t2++)
				if(!invalid(t1,t2) && flag[t1][t2]==0)
					if(!invalid(t1,t2) && getvalue(t1,t2))
                        rec(t1,t2,flag);
		}
	}
    return depth;
}


int main() {
    int maxim=0;
    
    cin >> m>> n ;
    int flag[11][11] = {0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
           cin >> arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1)
            {
                depth=0;
            	memset(flag,0,11*11);
                maxim = max(maxim,rec(i,j,flag));
            }
        }
    } 
    cout << maxim << endl;
    return 0;
}