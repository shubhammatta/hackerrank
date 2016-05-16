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
    while(t>0){
        int days;
        cin >> days;
        int stock[days];
        for(int i=0;i<days;i++)
            cin >> stock[i];
        int max=0,max_index;
        for(int i=0;i<days;i++){
        	if(max<stock[i]){
        		max = stock[i];
        		max_index = i;
        	}
        }
        int k = max_index+1;
        long long int count = 0;
        for(int i=0;i<max_index;i++){
        	count+= (max-stock[i]);
        }
        while(k!=days){
        	max = 0;
        	for(int i=k;i<days;i++){
	        	if(max<stock[i]){
	        		max = stock[i];
	        		max_index = i;
	        	}
        	}
        	for(int i=k;i<max_index;i++){
        		count+= (max-stock[i]);
        	}
        	k = max_index+1;
        }
        cout << count << endl;
        t--;
    }
    return 0;
}



