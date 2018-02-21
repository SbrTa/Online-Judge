#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 1000006
using namespace std;

long coin[6] = {1,5,10,25,50};
long long dp[6][30003];

long long change(long have, long i)
{
    if(i>=5)
    {
        if(have==0) return 1;
        return 0;
    }
    if(i<0) return 0;
    if(dp[i][have]!=-1) return dp[i][have];
    long long a=0,b=0;
    if(have-coin[i]>=0) a=change(have-coin[i],i);
    b=change(have,i+1);
    return dp[i][have] = a+b;
}

int main()
{
    long have;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%ld",&have))
    {
        long long ans=change(have,0);
        if(ans==1)
            printf("There is only 1 way to produce %ld cents change.\n",have);
        else
            printf("There are %lld ways to produce %ld cents change.\n",ans,have);
    }
    return 0;
}
