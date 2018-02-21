#include<bits/stdc++.h>
using namespace std;
//#define mem(a,n) memset(a,n,sizeof(a))

struct str
{
    long u,v,w;
};

bool cmp(str a, str b)
{
    if(a.w<b.w)
        return true;
    return false;
}

long par[200002];
str graph[200002];
long size[200002];

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
    //mem(par,-1);
    size[n]=1;
    par[n]=n;
    sort(graph,graph+n,cmp);
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
            size[i]=1;
            par[i]=i;
            sun+=graph[i].w;
        }
        //cout<<sun<<" "<<kruskal(m,n)<<endl;
        cout<<sun-kruskal(m,n)<<endl;
    }
    return 0;
}

