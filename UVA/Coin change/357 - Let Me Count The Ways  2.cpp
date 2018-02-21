#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define inf 1000006
using namespace std;


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int have,i,j, coin[6] = {1,5,10,25,50};
    long long dp[30003];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=0;i<5;i++)
    {
        for(j=coin[i]; j<=30000; j++)
            dp[j] += dp[j-coin[i]];
    }

    while(~scanf("%d",&have))
    {
        if(dp[have]==1)
            printf("There is only 1 way to produce %d cents change.\n",have);
        else
            printf("There are %lld ways to produce %d cents change.\n",dp[have],have);
    }

    return 0;
}
