#include<bits/stdc++.h>
using namespace std;
#define INF 0x7f7f

int cost[101][1001];

void set_cost(int n)
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cost[i][j]=(i==j)?0:INF;
}

void warshall(int n)
{
    int k,i,j;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
}

int main()
{
    int test,cs,node=0,edg,i,j;
    cin>>test;
    for(cs=1; cs<=test; cs++)
    {
        cin>>node>>edg;
        set_cost(node);
        for(i=1; i<=edg; i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            cost[u][v]=min(w,cost[u][v]);
            cost[v][u]=min(w,cost[v][u]);
        }
        warshall(node);
        printf("Case %d: ",cs);
        if(cost[1][node]<INF)
            cout<<cost[1][node]<<endl;
        else
            cout<<"Impossible\n";
    }
    return 0;
}
