#include<bits/stdc++.h>
using namespace std;

const long INF=0x7f7f7f7f;

struct node
{
    long u,w;
    node(long a, long b)
    {
        u=a;
        w=b;
    }
    bool operator < (const node & p) const
    {
        return w>p.w;
    }
};

vector<node>nd;
vector<long>edge[505];
vector<long>wt[505];
long dist[505];


void dijkstra(long n, long s)
{
    for(long i=0;i<=n;i++)
        dist[i]=INF;
    priority_queue<node>q;
    q.push(node(s,0));
    dist[s]=0;
    while(!q.empty())
    {
        node top=q.top();
        long u=top.u;
        for(long i=0;i<edge[u].size();i++)
        {
            long v=edge[u][i];
            long mx=dist[u]>wt[u][i]?dist[u]:wt[u][i];
            if(mx<dist[v])
            {
                dist[v]=mx;
                q.push(node(v,dist[v]));
            }
        }
        q.pop();
    }
}


int main()
{
    long T,t,i,n=0,m,s,a,b,c;
    scanf("%ld",&T);
    for(t=1;t<=T;t++)
    {
        for(i=0;i<=n;i++)
        {
            edge[i].clear();
            wt[i].clear();
        }
        scanf("%ld%ld",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%ld%ld%ld",&a,&b,&c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            wt[a].push_back(c);
            wt[b].push_back(c);
        }
        scanf("%ld",&s);
        dijkstra(n,s);
        printf("Case %ld:\n",t);
        for(i=0;i<n;i++)
        {
            if(dist[i]<INF)
                printf("%ld\n",dist[i]);
            else
                printf("Impossible\n");
        }
    }
    return 0;
}
