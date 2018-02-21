#include<bits/stdc++.h>
using namespace std;

long par[500005],flag[500005],mx;

long find_parent(long p)
{
    return (par[p]==-1)?p:find_parent(par[p]);
}

void Union(long a, long b)
{
    long u=find_parent(a);
    long v=find_parent(b);
    if(u!=v)
    {
        par[u]=v;
        long x=flag[u],y=flag[v];
        if(u==a&&flag[u]==0) x++;
        if(v==b&&flag[v]==0) y++;
        flag[v]=x+y;
        //cout<<flag[v]<<endl;
        if(flag[v]>mx)
            mx=flag[v];
    }
}

int main()
{
    long T;
    cin>>T;
    while(T--)
    {
        long node,edge,a,b;
        cin>>node>>edge;
        mx=0;
        for(long i=0;i<=node+3;i++)
        {
            par[i]=-1;
            flag[i]=0;
        }
        for(long i=0;i<edge;i++)
        {
            cin>>a>>b;
            Union(a,b);
        }
        cout<<mx<<endl;
    }
    return 0;
}
