#include<bits/stdc++.h>
using namespace std;

long m[1000000],dp[1000000];
long n;

long lis(long l)
{
    if(l==n) return 0;
    if(dp[l]>=0) return dp[l];
    long mxx = 0;
    for(long i=l+1;i<n;i++){
        if(m[i]<=m[l]){
            lis(i);
            if(dp[i]>mxx) mxx=dp[i];
        }
    }
    dp[l] = mxx+1;
    return dp[l];
}

int main()
{
    long i,j,cs=1;
    while(1){
        n=0;
        while(scanf("%ld",&m[n])==1){
            if(n==0 && m[n]==-1){
                n=-1;
                break;
            }
            if(m[n]==-1) break;
            n++;
        }
        if(n==-1) break;
        long mx=-1;
        for(i=0;i<=n;i++) dp[i]=-1;
        for(i=0;i<n;i++){
            lis(i);
            if(dp[i]>mx){
                mx=dp[i];
            }
        }
        if(cs>1) printf("\n");
        printf("Test #%ld:\n  maximum possible interceptions: %ld\n",cs++,mx);
    }
    return 0;
}
