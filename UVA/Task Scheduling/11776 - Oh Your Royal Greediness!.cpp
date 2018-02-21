#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#define inf 1000006
using namespace std;

int main()
{
    long n,i,cs=1;
    while(~scanf("%ld",&n) && n>=0)
    {
        long b,e;
        vector<pair<long,int> >v;
        for(i=0; i<n; i++)
        {
            scanf("%ld%ld",&b,&e);
            v.push_back(make_pair(b,-1));
            v.push_back(make_pair(e,1));
        }
        sort(v.begin(),v.end());
        //for(i=0;i<2*n;i++)
        //cout<<v[i].first<<" "<<-v[i].second<<endl;
        int ans=0,temp=0;
        for(i=0; i<2*n; i++)
        {
            temp+=-v[i].second;
            if(temp>ans) ans=temp;
        }
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}

