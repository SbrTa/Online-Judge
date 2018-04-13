#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#define inf 20000000
using namespace std;

int dp[inf+5];

void MST1_DP()
{
    //int *dp;
    //dp=new int [n+1];
    dp[1]=0;
    for(long i=2;i<=inf;i++)
    {
        dp[i]=dp[i-1]+1;
        if(i%2==0) dp[i] = min(dp[i] , dp[i/2]+1);
        if(i%3==0) dp[i] = min(dp[i] , dp[i/3]+1);
    }
}

int main()
{
    MST1_DP();
    long test,cs=1,n;
    scanf("%ld",&test);
    while(test--)
    {
        scanf("%ld",&n);
        printf("Case %ld: %d\n",cs++,dp[n]);
    }
    return 0;
}
