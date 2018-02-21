#include<bits/stdc++.h>
using namespace std;

struct node
{
    int u,v;
    double w;
    bool operator < (const node & s) const
    {
        return w<s.w;
    }
}graph[11000];

int par[105];

int Find(int p)
{
    if(par[p]==p)
        return p;
    return Find(par[p]);
}

double kruskal(int nd,int edg)
{
    double sum=0;
    sort(graph,graph+edg);
    for(int i=0;i<edg;i++)
    {
        int u=Find(graph[i].u);
        int v=Find(graph[i].v);
        if(u!=v)
        {
            par[u]=v;
            sum+=graph[i].w;
        }
    }
    return sum;
}

int main()
{
    int T,nd,i,j,t;
    double px[105],py[105],cost;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>nd;
        for(i=0;i<nd;i++)
            cin>>px[i]>>py[i];
        int edg=0;
        for(i=0;i<nd;i++)
        {
            par[i]=i;
            for(j=i+1;j<nd;j++)
            {
                cost=sqrt((px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]));
                graph[edg].u=i;
                graph[edg].v=j;
                graph[edg].w=cost;
                edg++;
            }
        }
        if(t>1)
            cout<<endl;
        printf("%.2lf\n",kruskal(nd,edg));
    }
    return 0;
}

