#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf 1000000000+111
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long t,cs=1,n,d;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&d);
        long v[300],i,j=0;
        v[j++]=0;
        v[j++]=0;
        for(i=0;i<n;i++)
        {
            long a;
            char c[10];
            scanf("%1s-%ld", c, &a);
            v[j++]=a;
            if(c[0]=='B') v[j++]=a;
        }
        v[j++]=d;
        v[j++]=d;
        long ans=0;

        for(i=2; i<j; i++)
            ans = max(ans,v[i]-v[i-2]);

        printf("Case %ld: %ld\n",cs++,ans);
    }
    return 0;
}
