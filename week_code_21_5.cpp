#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int> & a,const pair<int,int> & b){
    if(a.first == b.first) return a.second<b.second;
    return a.first<b.first;
}
#define x first
#define y second
#define pii pair<int,int>


bool chk(pii d1 , pii d2 ,pii A, pii B){
    int i1 = d1.x-d2.x;
    int j1 = d1.y-d2.y;         //vector d2d1
    int i2 = A.x-d2.x;
    int j2 = A.y-d2.y;          //vector d2A
    int Ad2d1 = i1*i2 + j1*j2;
    i1*=-1;j1*=-1;
    int i3 = B.x-d1.x;
    int j3 = B.y-d1.y;
    int Bd1d2 = i1*i2 + j1*j2;
    i3 = B.x-d2.x;
    j3 = B.y-d2.y;
    int fin = (i1*j2-i2*j1)*(i1*j3-i3*j1);
    if(((Ad2d1>=0 && Bd1d2>=0) || (Ad2d1<=0 && Bd1d2<=0)) && fin>0) return true;
    return false;
}

int valid(pair<int,int> a[]){
    int count=0;
    if(chk(a[0],a[1],a[2],a[3])) count++;
    if(chk(a[1],a[2],a[0],a[3])) count++;
    if(chk(a[2],a[3],a[1],a[0])) count++;
    if(chk(a[0],a[2],a[1],a[3])) count++;
    if(chk(a[0],a[3],a[2],a[1])) count++;
    if(chk(a[1],a[3],a[2],a[0])) count++;
    return count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,x,y;
    cin >> n;
    vector< pair<int,int> > p(n);
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        p[i] = make_pair(x,y);
    }
    long long ans=0;
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                for(int l=k+1;l<n;l++){
                    pair<int,int> a[4];
                    a[0] = p[i];a[1]=p[j];a[2]=p[k];a[3]=p[l];
                    ans+=valid(a);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

