#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#define mx 20005
#define inf 0x7f7f7f7f
using namespace std;

vector<long>edge[mx],cost[mx];
long d[mx];

struct node
{
    long u,w;
    node(long a, long b)
    {
        u=a;
        w=b;
    }
    bool operator < ( const node p ) const
    {
        if(p.w<w) return true;
        return false;
    }
};

void dijkstra(long n, long source)
{
    long i;
    for(i=0;i<=n;i++) d[i]=inf;
    priority_queue<node>q;
    q.push(node(source,0));
    d[source]=0;
    while(!q.empty())
    {
        node top=q.top();
        long u=top.u;
        for(i=0;i<edge[u].size();i++)
        {
            long v=edge[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                q.push(node(v,d[v]));
            }
        }
        q.pop();
    }
}


int main()
{
    long test,cs=1,n=1,edg,start,stop,i,j;
    cin>>test;
    while(test--)
    {
        for(i=0;i<=n;i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
        cin>>n>>edg>>start>>stop;
        for(i=0;i<edg;i++)
        {
            long u,v,w;
            cin>>u>>v>>w;
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        dijkstra(n,start);
        printf("Case #%ld: ",cs++);
        if(d[stop]==inf)
            cout<<"unreachable\n";
        else
            cout<<d[stop]<<endl;
    }
    return 0;
}
