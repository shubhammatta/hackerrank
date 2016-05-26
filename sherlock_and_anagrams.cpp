#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    
    string s;
    int t;cin >> t;
    while(t--){
        
        cin >> s;
        //sort(s.begin(),s.end());
        int n= s.size();
        vector<vector<string> > arr;
        vector<string> X;
        for(int i=0;i<n;i++){
            arr.push_back(X);
        }
       // cout << s << endl;
        //string arr[n][n];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
               // cout << j-i << endl;
                string mp = s.substr(i,j-i+1);
                sort(mp.begin(),mp.end());
                arr[j-i].push_back(mp);
            }
        }
        //  cout << " sdnfs" << endl;
        // for(int i=0;i<n;i++){
        //      for(int j=0;j<arr[i].size();j++)
        //         cout << arr[i][j] << " ";
        //     cout << endl;
        // }
        int count=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<arr[i].size()-1;j++){
                for(int k=j+1;k<arr[i].size();k++){
                if(arr[i][j]== arr[i][k])
                    count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}

