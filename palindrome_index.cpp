#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool palin(string s){
    for(int i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1])
            return false;
    } 
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;cin >> t;
    string s;
    while(t--)
        {
        cin >> s;
        int n=s.length();
        if(palin(s)) cout<< -1 << endl;
        else{
         string tmp=s;
            reverse(tmp.begin(),tmp.end());
            cout << tmp << endl;
            cout << n << endl;;
            for(int i=0;i<n;i++){
                if(s[i]!=tmp[i])
                {
                    if(s[n/2]==s[n/2+1]){
                        cout << i << endl;break;
                    }
                    else
                        {cout << n-i-1 << endl;break;}
                }
                    //{cout << i << endl;break;}
            }
                 
             }
                 
    
    }
    return 0;
}

