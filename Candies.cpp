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
    int N;cin >> N;
    int prev , current;
    int rating[N];
    for(int i=0;i<N;i++){
    	cin >> rating[i];
    }
    int value=1;long long int count = 0;
    int candy[N];
    candy[0]=1;
    for(int i=1;i<N;i++){
    	if(rating[i]>rating[i-1]){
    		candy[i] = candy[i-1]+1;
    	}
    	else candy[i]=1;
    }
    // for(int i=0;i<N;i++)
    // 	cout << rating[i] << "  candy  " << candy[i] << endl;
    // cout << endl << " --------------     " << endl << endl;
    for(int i=N-1;i>=2;i--){
    	if(rating[i-1]>=rating[i] && rating[i-2]>=rating[i-1]){
    		candy[i-1] = candy[i]+1;
    	}
    	else if(rating[i-1]==rating[i] && rating[i-2]<rating[i-1]) candy[i-1] = candy[i]+1;
    	//else;
    }
    for(int i=0;i<N;i++)
    	{
    		count+=candy[i];
    		// cout << rating[i] << "  candy  " << candy[i] << endl;
    	}
    cout << count <<endl;
    return 0;
}

