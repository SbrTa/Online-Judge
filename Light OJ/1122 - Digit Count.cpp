/*
If this code works, it was written by Subrata Roy.
If not, I don’t know who wrote it..
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>

#define inInt(n) scanf("%d",&n)
#define inLong(n) scanf("%ld",&n)
#define inLong2(n,m) scanf("%ld%ld",&n,&m)
#define inLong3(n,m,l) scanf("%ld%ld%ld",&n,&m,&l)
#define inLL(n) scanf("%lld",&n)
#define inLL2(n,m) scanf("%lld%lld",&n,&m)
#define inFloat(n) scanf("%f",&n)
#define inDouble(n) scanf("%lf",&n)
#define inLD(n) scanf("%Lf",&n)
#define inStr(n) scanf("%s",n)
#define inChar(n) scanf("%c",&n)

#define Spc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld:",n++)

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;

long num[15],n,m,dp[15][15];


long F(long digit, long level)
{
    if(level>=m) return 1;
    if(dp[level][digit]!=-1) return dp[level][digit];
    long ret = 0;
    for(long i=0; i<n; i++){
        if(level==0 || abs(digit-num[i])<=2)
            ret+=F(num[i],level+1);
    }
    return dp[level][digit]=ret;
}

int main()
{
    long test,cs=1;
    long a,b,i,j;
    inLong(test);
    while(test--){
        inLong2(n,m);
        for(i=0;i<n;i++) inLong(num[i]);
        for(i=0;i<=11;i++) for(j=0;j<=11;j++) dp[i][j]=-1;
        long ans = F(0,0);
        Case(cs);
        printf(" %ld\n",ans);
    }
    return 0;
}

