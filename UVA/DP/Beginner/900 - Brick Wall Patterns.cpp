#include<stdio.h>

int main()
{
    long long n,i,dp[55];
    //DP
    dp[1]=1;
    dp[2]=2;
    for(i=3;i<=50;i++)
        dp[i]=dp[i-1]+dp[i-2];
    while(~scanf("%lld",&n) && n)
    {
        printf("%lld\n",dp[n]);
    }
    return 0;
}
