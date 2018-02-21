#include<stdio.h>
#include<iostream>
#define inf 0x7f7f
using namespace std;

int graph[1000][1000];

void reset(int n)
{
    int i,j,k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
            graph[i][j]=inf;
        graph[i][j]=0;
    }
}

void MinMaxWarshal(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                graph[i][j]=min(graph[i][j],max(graph[i][k],graph[k][j]));
}

int main()
{
    int n,edg,q,cs=1,i;
    while(cin>>n>>edg>>q)
    {
        if(n==0&&edg==0&&q==0)
            break;
        reset(n);
        for(i=1;i<=edg;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            graph[u][v]=w;
            graph[v][u]=w;
        }
        MinMaxWarshal(n);
        if(cs>1)
            cout<<endl;
        cout<<"Case #"<<cs++<<endl;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            if(graph[x][y]==inf)
                cout<<"no path\n";
            else
                cout<<graph[x][y]<<endl;
        }
    }
    return 0;
}
