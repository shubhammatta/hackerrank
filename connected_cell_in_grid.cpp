#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int n , m;
int arr[11][11]={0};
int currentDepth;
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
int findMaxDepth(int boolean[][11], int i, int j) {
    // Check if i, j (indexes) are within the size of array
    // Check if the cell is already traversed or not using boolean array
    // Check if the cell value is 1 before counting it as part of a sector
    if(i >= 0 && i < m &&  j >=0 && j <n
                && boolean[i][j] != true && arr[i][j] != 0) {
        currentDepth++;
 
        // Mark the status of the cell for backtracking purpose
        boolean[i][j] = true;
 
        // left traversal
        findMaxDepth(boolean, i-1, j);
        // right traversal
        findMaxDepth(boolean, i+1, j);
 
        // top traversal
        findMaxDepth(boolean, i, j-1);
        // bottom traversal
        findMaxDepth(boolean, i, j+1);
 
        // Top-Bottom diagnol
        // diagnol-down traversal
        findMaxDepth(boolean, i+1, j+1);
        // diagnol-up traversal
        findMaxDepth(boolean, i-1, j-1);
 
        // Bottom-Top diagnol
        // diagnol-down traversal
        findMaxDepth(boolean, i+1, j-1);
        // diagnol-up traversal
        findMaxDepth(boolean, i-1, j+1);
    }
    return currentDepth;
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
            	currentDepth=0;
            	memset(flag,0,11*11);
                maxim = max(maxim,findMaxDepth(flag,i,j));
            }
        }
    } 
    cout << maxim << endl;
    return 0;
}