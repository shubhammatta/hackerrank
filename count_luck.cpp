#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int n , m;
int arr[101][101]={0};
int depth,wave;
long long int max5(long long int a,long long int b,long long int c){
    return max(a,max(b,c));
}

class destination{
public:
    int finx,finy;
};

class Point{
public:
    int x, y;
    Point(){;}
    Point(int a,int b){
        x = a ;y=b;
    }
};
Point back[101][101];
int invalid(long int i,long int j){
    if(i>=0 && i<m && j>=0 && j<n) return 0;
    else return 1;
}
int getvalue(long int i,long int j){
    if(i>=0 && i<m && j>=0 && j<n) return arr[i][j];
    else return 0;
}

int rec(int i,int j,int flag[][101],int desx, int desy ,int depth,int px , int py){
	// for(int p=0;p<m;p++){
	// 		for(int k=0;k<n;k++) cout << flag[i][j] << " ";
	// 			cout << endl;
	// 	}
    if(i==desx && j==desy)
    {
        Point p(px,py);
        ::back[i][j] = p;
        //cout << "got it " << endl;
        return depth;
    }
    if(!invalid(i,j) && !flag[i][j] && arr[i][j]==1)
    {
		flag[i][j]=1;
        Point p(px,py);
        ::back[i][j] = p;
        //cout << back[i][j].x << " " << p.y << endl;

		depth++;
        int count=0;
		long long int maxim = 0;
        for(int t1=i-1;t1<i+2;t1++){
            for(int t2=j-1;t2<j+2;t2++)
                if(abs(t1-i+t2-j)==1)
                {
                    //printf("( %d , %d  ) from ( %d , %d )\n",t1,t2,i,j);
                    if(!invalid(t1,t2) && flag[t1][t2]==0 && getvalue(t1,t2))
                    {
                        rec(t1,t2,flag , desx , desy,depth,i,j);
                    }
                }
        }

	}
    return depth;
}
int main() {
    //int maxim=0;
    int t;cin >> t;
    while(t--)
    {
        wave=0;
        int flag[101][101] = {0};

        memset(back,0,101*101*sizeof(int));
        memset(arr,0,101*101*sizeof(int));
        memset(flag,0,101*101*sizeof(int));
        cin >> m>> n ;
        
    
        char x;wave=0;
        destination des;
        destination start;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                cin >>x;
                if(x=='.' || x=='*' || x=='M'){
                    arr[i][j]=1;
                }
                if(x=='*'){
                    des.finx = i;
                    des.finy = j;
                }
                if(x=='M'){
                    start.finx= i;
                    start.finy= j;
                }
            }
        }
        Point init(-1,-1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                back[i][j] = init;
            }
        }
        int k;cin >> k;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++)
        //     {
        //         cout << arr[i][j];
        //     }
        //     cout << endl;
        // }
        depth = rec(start.finx , start.finy , flag, des.finx , des.finy,1,init.x,init.y);
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //        cout << "("<<back[i][j].x << "," << back[i][j].y << ")\t";
        //     }
        //     cout << endl;
        // }
        int sx = des.finx;
        int sy = des.finy;
        //cout<< des.finx << " " << des.finy << endl;
        int dir;
        int count;
        // if(back[sx][sy].x>sx){
        //     dir=1;sx = back[sx][sy].x;
        // }
        // else if(back[sx][sy].x<sx){
        //     dir = 3;sx = back[sx][sy].x;
        // }
        // else if(back[sx][sy].y<sy){
        //     dir = 0;sy = back[sx][sy].y;
        // }
        // else {dir=2;sy = back[sx][sy].y;}
         count = getvalue(back[sx][sy].x+1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y+1) +
                  getvalue(back[sx][sy].x-1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y-1) ;
                if(count > 2) wave++;
        int tempx = back[sx][sy].x; int tempy= back[sx][sy].y;
        sx = tempx ; sy=tempy;
        ///cout << wave << " " << sx << " " << sy<<" " << back[sx][sy].x << " "<< back[sx][sy].y << " "<< start.finx <<" " << start.finy <<endl;
        
        //cout << getvalue(3,4) + getvalue(3,2) + getvalue(2,3) <<" fd" <<endl;
        while(sx!=start.finx || sy!=start.finy){
            if(back[sx][sy].x>sx){
                
                 int count = getvalue(back[sx][sy].x+1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y+1) +
                  getvalue(back[sx][sy].x-1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y-1) ;
                if(count > 2) wave++;dir=1;
                sx = back[sx][sy].x;
            }
            else if(back[sx][sy].x<sx){
                
                int count = getvalue(back[sx][sy].x+1,back[sx][sy].y) + 
                getvalue(back[sx][sy].x,back[sx][sy].y+1) + getvalue(back[sx][sy].x-1,back[sx][sy].y) + 
                getvalue(back[sx][sy].x,back[sx][sy].y-1) ;
                if(count > 2) wave++;dir=3;
                    sx = back[sx][sy].x;
            }
            else if(back[sx][sy].y<sy){
                
                 int count = getvalue(back[sx][sy].x+1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y+1) + 
                 getvalue(back[sx][sy].x-1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y-1) ;
                if(count > 2) wave++;dir=0;
                    sy = back[sx][sy].y;
            }
            else {
                
                 int count = getvalue(back[sx][sy].x+1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y+1) + 
                 getvalue(back[sx][sy].x-1,back[sx][sy].y) + getvalue(back[sx][sy].x,back[sx][sy].y-1) ;
                if(count > 2) wave++;dir=2;
                sy = back[sx][sy].y;          
            }
           //cout << wave << " " << sx << " " << sy<<" " << back[sx][sy].x << " "<< back[sx][sy].y << " "<< start.finx <<" " << start.finy <<endl;
         }
         count = getvalue(start.finx+1,start.finy) + getvalue(start.finx,start.finy+1) + 
                 getvalue(start.finx-1,start.finy) + getvalue(start.finx,start.finy-1) ;
                if(count == 2) wave++;dir=2;
       // cout << wave << endl;
        if(wave==k){
            cout << "Impressed" << endl;
        }
        else cout << "Oops!" << endl;
    }
    return 0;
}