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
    long target,i,j,dp[7500],coin[10] = {1,5,10,25,50};
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=0;i<5;i++)
    {
        for(j=coin[i]; j<=7489; j++)
            dp[j] += dp[j-coin[i]];
    }

    while(~scanf("%ld",&target))
    {
        printf("%ld\n",dp[target]);
    }
    return 0;
}
