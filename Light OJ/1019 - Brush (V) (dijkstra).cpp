#include<bits/stdc++.h>
using namespace std;

const int INF=0x7f7f;

struct node
{
    int u,w;
    node(int a, int b)
    {
        u=a;
        w=b;
    }
    bool operator < (const node & p) const
    {
        return w>p.w;
    }
};

//vector<node>nd;
vector<int>edge[101];
vector<int>wt[101];
int dist[101];

void dijkstra(int n, int s)
{
    for(int i=0;i<=n;i++)
        dist[i]=INF;
    priority_queue<node>q;
    q.push(node(s,0));
    dist[s]=0;
    while(!q.empty())
    {
        node top=q.top();
        int u=top.u;
        for(int i=0;i<edge[u].size();i++)
        {
            int v=edge[u][i];
            if(dist[u]+wt[u][i]<dist[v])
            {
                dist[v]=dist[u]+wt[u][i];
                q.push(node(v,dist[v]));
            }
        }
        q.pop();
    }
}


int main()
{
    int T,t,i,n=0,m,s,a,b,c;
    cin>>T;
    for(t=1;t<=T;t++)
    {
        for(i=0;i<=n;i++)
        {
            edge[i].clear();
            wt[i].clear();
        }
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
            cin>>a>>b>>c;
            a--;
            b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
            wt[a].push_back(c);
            wt[b].push_back(c);
        }
        dijkstra(n,0);
        if(dist[n-1]<INF)
            printf("Case %d: %d\n",t,dist[n-1]);
        else
            printf("Case %d: Impossible\n",t);
    }
    return 0;
}
