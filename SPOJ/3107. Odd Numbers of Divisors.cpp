#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#define inf 10000000000
using namespace std;

vector<long long>ans[10002];

void Pre()
{
    long long i,n,c,m,in;
    for(n=2;n*n<=inf;n++)
    {
        in=1;
        m=n;
        for(i=2;i*i<=m;i++)
        {
            c=0;
            while(m%i==0)
            {
                m=m/i;
                c++;
            }
            if(c) in=in*(c*2+1);
        }
        if(m>1) in=in*3;
        ans[in].push_back(n*n);
    }
}

int main()
{
    Pre();
    //cout<<"hi\n";
    long long t,m,low,high,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&m,&low,&high);
        long long a = lower_bound(ans[m].begin(),ans[m].end(),low) - ans[m].begin();
        long long b = upper_bound(ans[m].begin(),ans[m].end(),high) - ans[m].begin();
        printf("%lld\n",b-a);
    }
    return 0;
}

