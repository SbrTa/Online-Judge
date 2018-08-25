#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,d,a[203],dp[203][13][23];

ll call(ll i, ll taken, ll sum)
{
    if(taken==m){
        if(sum==0) return 1;
        return 0;
    }
    if(i>=n) return 0;
    if(dp[i][taken][sum]!=-1) return dp[i][taken][sum];
    ll s  = sum+a[i];
    s = (s%d+d)%d;
    return dp[i][taken][sum] = call(i+1,taken+1,s) + call(i+1,taken,sum);
}

int main()
{
    ll test,cs=1,i,j,k,q;
    scanf("%lld",&test);
    while(test--){
        printf("Case %lld:\n",cs++);
        scanf("%lld%lld",&n,&q);
        for(i=0;i<n;i++) scanf("%lld",&a[i]);
        while(q--){
            scanf("%lld%lld",&d,&m);
            for(i=0;i<=n+1;i++)
                for(j=0;j<=m+1;j++)
                    for(k=0;k<=d+1;k++) dp[i][j][k]=-1;
            cout<<call(0,0,0)<<endl;
        }
    }
    return 0;
}
