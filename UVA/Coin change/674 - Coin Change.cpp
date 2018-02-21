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

long coin[10] = {1,5,10,25,50};
long dp[6][7500];

long change(long i,long n)
{
    long a=0,b=0;
    if(i>=5)
    {
        if(n==0) return 1;
        else return 0;
    }
    if(dp[i][n]!=-1) return dp[i][n];
    if(n-coin[i]>=0) a=change(i,n-coin[i]);
    b=change(i+1,n);
    return dp[i][n] = a+b;
}

int main()
{
    long n,i,j;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%ld",&n))
    {
        printf("%ld\n",change(0,n));
    }
    return 0;
}
