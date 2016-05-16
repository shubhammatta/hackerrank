//CREATED BY VOIDCODER
//SM
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
#include <limits.h>
#define eps 1e-9
#define bs 1000000007
#define bsize 512
#define FOR(i,start,end) for(size_t i=start;i<end;i++)
#define rFOR(i,end,start) for(size_t i=end,i>=start;i--)
#define MOD 1000000007
#define line cout<<endl
using namespace std;
#define ll long long int 
#include <sstream>

string IntToString (int a)
{
    ostringstream temp;
    temp<<a;
    return temp.str();
}

ll powerwithmodulus(ll base, ll exponent,ll modulus)
{
    ll result = 1;
    base%=modulus;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

// int gcd(int a, int b)
// {
//     while(b) b ^= a ^= b ^= a %= b;
//     return a;
// }

// long long sum(long long N){
//     if(N/10==0) return N*(N+1)/2;
//     int i=0;
//     long long n=N;
//     while(n/10!=0){
//         i++;
//         n/=10;
//     }
//     int p=pow(10,i);
//     return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + sum(N%p));
// }
void printArray(int arr[] , int n){
	FOR(i,0,n) cout << arr[i] << " " ;
	line;
}

bool decreasing(string a){
    for(int i=0;i<a.length()-1;i++){
        if(a[i]<a[i+1])
            return false;
    }
    return true;
}

int main(){
    int t;cin>>t;
    while(t--){
    	string s;cin >> s;
    	int len = s.length();
    	if(decreasing(s)){
    		cout << "no number" << endl;
    	}
    	else{
    		if(s[len-2]<s[len-1]){
    			s[len-1] = s[len-2] + s[len-1] -(s[len-2]=s[len-1]);
    		}
    		else{
    			int k=n-2;
    			for(k=n-2;k>=1;k--){
    				if(s[k-1] < s[k]) break;
    			}
    		}
    	}
    }
    return 0;
}

