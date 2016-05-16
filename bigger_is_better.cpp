/*
***************************************************************************************************************
 
                          Author : SHUBHAM MATTA
						  HACKERRANK HANDLE: voidcoder
                          SPOJ Handle: shubhammatta
                          Codeforces Handle: ironman1
 
**************************************************************************************************************
*/
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
#define ll long long int
#define LD long double
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mp make_pair
#define memory(x,y) memset(x,y,sizeof(x))
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define ub(X,v) upper_bound(X.begin(),X.end(),v)
#define lb(X,v) lower_bound(X.begin(),X.end(),v)
#define ii pair<ll,ll>
#define F first
#define S second

using namespace std;
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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}



