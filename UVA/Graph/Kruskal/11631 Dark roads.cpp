#include<bits/stdc++.h>
using namespace std;

struct str
{
    long u,v,w;
    bool operator < (const str & s) const
    {
        return w < s.w;
    }
}graph[200002];

long par[200002],size[200002];

long parent(long p)
{
    if(par[p]==p)
        return p;
    else
        return parent(par[p]);
}

long kruskal(long m,long n)
{
    long cnt=0,sum=0;
    sort(graph,graph+n);
    for(long i=0;i<n;i++)
    {
        long x = parent(graph[i].u);
        long y = parent(graph[i].v);
        if(x!=y)
        {
            if(size[x]>size[y])
                swap(x,y);
            size[y]+=size[x];
            par[x]=y;
            sum+=graph[i].w;
            cnt++;
            if(cnt==m-1)
                break;
        }
    }
    return sum;
}

int main()
{
    long m,n;
    while(cin>>m>>n&&m!=0&&n!=0)
    {
        long sun=0;
        for(long i=0;i<n;i++)
        {
            cin>>graph[i].u>>graph[i].v>>graph[i].w;
            par[i]=i;
            size[i]=1;
            sun+=graph[i].w;
        }
        cout<<sun-kruskal(m,n)<<endl;
    }
    return 0;
}
