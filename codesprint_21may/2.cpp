#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(string s,int n){
    for(int i=n-1;i>=n/2;i--){
        if(s[i]!=s[n-i-1])
            return false;
    }
    return true;
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int p = k;
    int i=n-1;
    
    if(n==1){
        if(p>0){
            cout << 9 << endl;return 0;
        }
        else cout << s << endl;return 0;
    }
    
    
    for(i=n-1;i>=n/2;i--){
        if(s[i] != s[n-i-1])
        {
            p--;
        }
    }
    if(p<0)
        cout << -1 << endl;
    else{
        for(i=n-1;i>=n/2;i--){
        if(s[i] != s[n-i-1])
        {
            char x = max(s[i],s[n-i-1]);
            if(p>0){
                if(s[i]=='9' || s[n-i-1]=='9')
                    p++;
                s[i]='9';s[n-i-1]='9';
                p--;
            }
            else
                {
                s[i]=x;s[n-i-1]=x;
            }
        }
    }
        //cout << p << endl;
        if(p<=0)
        cout << s << endl;
        else{
            if(p==1){
                if(n%2==1){
                    s[n/2]='9';
                    cout << s << endl;return 0;
                }
            }
            else{
                int tmp=0;
                for(int i=0;i<n/2;i++){
                    if(s[i]!='9' && p>=2){
                        s[i]='9';s[n-i-1]='9';p-=2;
                    }
                }
                if(p>0 && n%2==1 && s[n/2]!='9' ) s[n/2]='9';
            }
            cout << s << endl; return 0;
        }
    }
    return 0;
}

