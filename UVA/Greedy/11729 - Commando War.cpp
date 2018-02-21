#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf -99999999
using namespace std;

int main()
{
    long n,i,cs=1;
    while(~scanf("%ld",&n) && n)
    {
        vector<pair<long,long> >v;
        long a=0,b=0,x,y;
        for(i=0;i<n;i++)
        {
            scanf("%ld%ld",&x,&y);
            v.push_back(make_pair(y,x));
        }
        sort(v.begin(),v.end());
        for(i=v.size()-1; i>=0; i--)
        {
            a+=v[i].second;
            b-=v[i].second;
            b=max(b,v[i].first);
        }
        printf("Case %ld: %ld\n",cs++,a+b);
    }
    return 0;
}
