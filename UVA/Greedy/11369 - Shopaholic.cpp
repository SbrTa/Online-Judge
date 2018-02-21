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
    long t,n,i,a[20005];
    scanf("%ld",&t);
    while(t--)
    {
        long ans=0;
        scanf("%ld",&n);
        for(i=0;i<n;i++)
            scanf("%ld",&a[i]);
        sort(a,a+n);
        for(i=n-3;i>=0;i-=3)
            ans+=a[i];
        printf("%ld\n",ans);
    }
    return 0;
}
