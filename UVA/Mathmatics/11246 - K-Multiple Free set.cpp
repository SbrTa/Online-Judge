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
    long t,n,k,i,j;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld%ld",&n,&k);
        long p=1,ans=n;
        while(p<=n)
        {
            p=p*k;
            ans = ans - (n/p);
            p=p*k;
            ans = ans + (n/p);
        }
        printf("%ld\n",ans);
    }
    return 0;
}

