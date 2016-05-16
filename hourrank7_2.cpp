#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int size;

int score(long long int arr[],int val, int size){
    for(int i=0;i<size;i++){
        if(2*arr[i]==arr[size-1] && size!=1){
          
            long long int cop1[i+1];
            for(int j=0;j<=i;j++){
                cop1[j] = arr[j];
               
            }
       
            long long int cop2[size-i-1];
            for(int k=i+1;k<=size-1;k++){
                cop2[k-i-1] = arr[k] -arr[i];
              
            }
           
            return max(score(cop1,val+1,i+1),score(cop2,val+1,size-i-1));
        }
    }
    return val;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;//test cases
    cin >> t;
    while(t>0){

        cin >> size ;
        long long int * arr = new long long int[size];
        for(int i=0;i<size;i++){
            cin >> arr[i];
        }
        for(int i=1;i<size;i++)
            arr[i] = arr[i] + arr[i-1];
       
        printf("%d\n" , score(arr,0,size));
        t--;
    }
    return 0;
}


