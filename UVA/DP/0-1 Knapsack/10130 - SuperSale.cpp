#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define inf 1111
#define MX 2000000+2
#define weight first
#define price second
using namespace std;

int knapsack(vector<pair<int,int> >item, int n, int can)
{
    int dp[n+1][can+1],w,i;

    for(i=0;i<=n;i++)
    {
        for(w=0;w<=can;w++)
        {
            if(i==0 || w==0)
            {
                dp[i][w]=0;
                continue;
            }
            int ww=item[i-1].weight;
            int pp=item[i-1].price;

            if(ww<=w)
                dp[i][w] = max( dp[i-1][w] , dp[i-1][w-ww]+pp );
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][can];
}


int main()
{
    int t,n,m,i;
    vector<pair<int,int> >item;

    scanf("%d",&t);
    while(t--)
    {
        item.clear();
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            int p,w;
            scanf("%d%d",&p,&w);
            item.push_back(make_pair(w,p));
        }

        scanf("%d",&m);
        int ans=0,can;
        while(m--)
        {
            scanf("%d",&can);
            ans=ans+knapsack(item,n,can);
        }
        printf("%d\n",ans);
    }
    return 0;
}
