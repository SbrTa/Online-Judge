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
    long day[111],night[111],n,d,p,i;
    while(~scanf("%ld%ld%ld",&n,&d,&p) && n&&d&&p)
    {
        for(i=0;i<n;i++) scanf("%ld",&day[i]);
        for(i=0;i<n;i++) scanf("%ld",&night[i]);
        sort(day,day+n);
        sort(night,night+n);
        long ans=0;
        for(i=0;i<n;i++)
        {
            if(day[i]+night[n-i-1]>d) ans += ((day[i]+night[n-i-1]-d)*p);
        }
        printf("%ld\n",ans);
    }
    return 0;
}

