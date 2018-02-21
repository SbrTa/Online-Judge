#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#define LL long long
#define inf 1000006
using namespace std;

LL coin[11+1] = {5,10,20,50,100,200, 500,1000,2000,5000,10000};
LL dp[30005];

int main()
{
    LL have,i,j;
    char s[10];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=0;i<11;i++)
    {
        for(j=coin[i]; j<=30001; j++)
            dp[j] += dp[j-coin[i]];
    }
    while(cin>>s)
    {
        int i=0,a=0;
        while(s[i]!='.')
        {
            a=a*10+(s[i]-'0');
            i++;
        }
        have = a*100;
        i++;
        a=0;
        while(i<strlen(s))
        {
            a=a*10+(s[i]-'0');
            i++;
        }
        have = have+a;
        if(have==0) break;
        printf("%6s%17lld\n",s,dp[have]);
    }
    return 0;
}

