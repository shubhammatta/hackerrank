#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<pair<int,string> > se;
bool visited[35] = {0};
int maxv = -1;
void perm(pair<int,int>* ed,int* va,string s,int count,int m,int an)
{
    if(count == m)
    {
        maxv = max(an,maxv);
        se.insert(make_pair(an,s));
    }
    else{
        int a = ed[count].first;
        int b = ed[count].second;
        visited[a] = true;
        visited[b] = true;
        if(s[a-1] == '1' && s[b-1] == '1')
        {
            s[a-1] = '0';
            if(an-va[a]>=maxv)
                perm(ed,va,s,count+1,m,an-va[a]);
            s[b-1] = '0';
            s[a-1] = '1';
            if(an-va[b]>=maxv)
            perm(ed,va,s,count+1,m,an-va[b]);
            s[b-1] = '0';
            s[a-1] = '0';
            if(an-va[a]-va[b]>=maxv)
            perm(ed,va,s,count+1,m,an-va[a]-va[b]);
            s[b-1] = '1';
            s[a-1] = '1';
        }
        else if(s[a-1] == '1')
        {
            if(an>=maxv)
            perm(ed,va,s,count+1,m,an);
            s[a-1] = '0';
            if(an-va[a]>=maxv)
            perm(ed,va,s,count+1,m,an-va[a]);
            s[a-1] = '1';
        }
        else if(s[b-1] == '1')
        {
            if(an>=maxv)
            perm(ed,va,s,count+1,m,an);
            s[b-1] = '0';
            if(an-va[b]>=maxv)
            perm(ed,va,s,count+1,m,an-va[b]);
            s[b-1] = '1';
        }
        else{
            if(an>=maxv)
            perm(ed,va,s,count+1,m,an);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n,m;
    cin>>n>>m;
    int* va = new int[n+1];
    long long int an = 0;
    for(int i = 1;i<n+1;i++)
    {
        cin>>va[i];
        an+=va[i];
    }
    string s = "";
    for(int i = 0;i<n;i++)
    {
        s+="1";
    }
    pair<int,int> *ed = new pair<int,int>[m];
    for(int i = 0;i<m;i++)
    {
        cin>>ed[i].first>>ed[i].second;    
    }
    perm(ed,va,s,0,m,an);
    int count_v = 0;
    for(int i = 1 ;i<=n;i++)
{
        if(!visited[i] && va[i] == 0)
       {
            count_v++;
        }
    }
    std::set< pair<int,string> >::reverse_iterator rit;
    int maxv = (*(se.rbegin())).first;
    int co = 0;
    for (rit=se.rbegin(); rit != se.rend(); ++rit)
        {
        if(maxv == (*rit).first)
        {
            co++;
        }
        else break;
    }
    cout<<maxv<<" "<<(long long int)co*pow(2,count_v)<<endl;
    return 0;
}