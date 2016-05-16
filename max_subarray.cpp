#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



// int maxSumcont(int a[], int size)
// {
//     int max_so_far = 0, max_ending_here = 0;
 
//     for (int i = 0; i < size; i++)
//     {
//         max_ending_here = max_ending_here + a[i];
//         if (max_ending_here < 0)
//             max_ending_here = 0;
//         if (max_so_far < max_ending_here)
//             max_so_far = max_ending_here;
//     }
//     int max1 = -10001 ;
//     if(max_so_far<=0){
//         for(int i=0;i<size;i++)
//             if(max<a[i])max=a[i];
//         max_so_far = max;
//     }
    
//     return max_so_far;
// }



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin >> t;
    while(t>0){
        int n;
        cin >> n;
        int arr[n];
        int * a = arr;
        for(int i=0;i<n;i++)
            scanf("%d ",&arr[i]);
        long long int ans[n];
        int size = n;
        int max_so_far = 0, max_ending_here = (a[0]>0)?a[0]:0;
 
        int max1 = -10001 ;
        for(int i=0;i<size;i++)
                if(max1<a[i])max1=a[i];
        
        
        
        long long int X=0;
        ans[0] = a[0];
        for(size_t i=1;i<n;i++){
            max_ending_here = max_ending_here + a[i];
            if (max_ending_here < 0)
                max_ending_here = 0;
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
            
            
            for(size_t j=0;j<i;j++){
                X = max(X,a[i]+ans[j]);
            }
            ans[i] = X;
        }
        if(max_so_far<=0){
            max_so_far = max1;
        }
        if(ans[n-1]<=0){
            ans[n-1]= max1;
        }
        long long int maxcont = max_so_far;
        long long int maxnoncont = ans[n-1];
        printf("%lld %lld\n",maxcont, maxnoncont);
        t--;
    }
    return 0;
}

