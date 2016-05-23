#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int A;
    int B;
    int C;
    int D;
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    sort(arr,arr+4);
    A=arr[0];
    B=arr[1];
    C=arr[2];
    D=arr[3];
    int count=0;
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            for(int k=1;k<=C;k++){
                for(int l=1;l<=D;l++){
                    //int tmp = i^j;
                    int tmp = i^j^k^l;
                    if(tmp!=0 && i<=j && j<=k && k<=l) {
                       // cout << i << " " << j << " " << k << " "<< l <<  " xor is  "<< tmp << endl;
                        count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}

