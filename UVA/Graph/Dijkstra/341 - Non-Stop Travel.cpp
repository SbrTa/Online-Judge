#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>

#define inI(n)      scanf("%d",&n)
#define inL(n)      scanf("%ld",&n)
#define inL2(n,m)   scanf("%ld%ld",&n,&m)
#define inL3(n,m,l) scanf("%ld%ld%ld",&n,&m,&l)
#define inLL(n)     scanf("%lld",&n)
#define inLL2(n,m)  scanf("%lld%lld",&n,&m)
#define inDouble(n) scanf("%lf",&n)
#define inStr(n)    scanf("%s",n)
#define inCh(n)     scanf("%c",&n)
#define PB          push_back
#define LL          long long

#define mset(a,n)   memset(a,n,sizeof(a))
#define sortV(v)    sort(v.begin(),v.end())
#define sortA(a,n)  sort(a,a+n)
#define FOR(i,a,b)    for(i=a;i<=b;i++)

#define Spc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld:",n++)

#define eps 10e-9
#define inf 0x7f7f7f7f
#define mod 10000007
#define MX 111
#define PI 2*acos(0.0)
using namespace std;

vector<long>edge[100],cost[100];
long d[100],p[100];

struct node
{
    long u,w;
    node(long a, long b)
    {
        u=a;
        w=b;
    }
    /*bool operator < (const node p) const
    {
        if(p.w<w)   return true;
        return false;
    }*/
};

bool operator < (node a, node b)
{
    //if(a.w>b.w) return true;
    //return false;
    return (a.w>b.w);
}

void dijkstra(long n, long source)
{
    long i;
    for(i=0; i<=n; i++)   d[i]=inf;
    priority_queue<node>q;
    q.push(node(source,0));
    d[source]=0;
    while(!q.empty())
    {
        node top=q.top();
        long u=top.u;
        for(i=0; i<edge[u].size(); i++)
        {
            long v=edge[u][i];
            if(d[u]+cost[u][i]<d[v])
            {
                d[v]=d[u]+cost[u][i];
                q.push(node(v,d[v]));
                p[v]=u;
            }
        }
        q.pop();
    }
}

void path(long s, long t)
{

    int arr[15],ind=0,i;
    while(s!=t)
    {
        arr[ind++]=t;
        t=p[t];
    }
    arr[ind++]=s;
    for(i=ind-1; i>=0; i--)
        //cout<<" "<<arr[i];
        printf(" %ld",arr[i]);
}
int main()
{
    long n=1,i,j,m,u,v,w,start,stop,cs=1;
    while(inL(n) && n)
    {
        for(i=0; i<=n; i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
        for(i=0; i<=n; i++)   p[i]=i;
        for(u=1; u<=n; u++)
        {
            inL(m);
            while(m--)
            {
                inL2(v,w);
                edge[u].push_back(v);
                cost[u].push_back(w);
            }
        }
        inL2(start,stop);
        dijkstra(n,start);
        printf("Case %ld: Path =",cs++);
        path(start,stop);
        printf("; %ld second delay\n",d[stop]);
    }
    return 0;
}
