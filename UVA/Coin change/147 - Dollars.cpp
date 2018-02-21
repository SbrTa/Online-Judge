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
LL dp[12][30005];

LL change(LL have, LL i)
{
    if(i>=11)
    {
        if(have==0) return 1;
        return 0;
    }
    if(dp[i][have]!=-1) return dp[i][have];
    LL a=0,b=0;
    if(have-coin[i]>=0) a=change(have-coin[i], i);
    b=change(have,i+1);
    return dp[i][have] = a+b;
}

int main()
{
    LL have;
    char s[10];
    memset(dp,-1,sizeof(dp));
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
        printf("%6s%17lld\n",s,change(have,0));
    }
    return 0;
}
