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

#define inInt(n) scanf("%d",&n)
#define inLong(n) scanf("%ld",&n)
#define inLong2(n,m) scanf("%ld%ld",&n,&m)
#define inLong3(n,m,l) scanf("%ld%ld%ld",&n,&m,&l)
#define inLL(n) scanf("%lld",&n)
#define inLL2(n,m) scanf("%lld%lld",&n,&m)
#define inFloat(n) scanf("%f",&n)
#define inDouble(n) scanf("%lf",&n)
#define inLD(n) scanf("%Lf",&n)
#define inStr(n) scanf("%s",n)
#define inChar(n) scanf("%c",&n)

#define Spc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld:",n++)

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;

struct info
{
    long u,v,w;
    bool operator < (const info &p) const{
        return w<p.w;
    }
};

info graph[6006];
long par[222],top;

long parent(long r)
{
    if(par[r]==r) return r;
    return par[r] = parent(par[r]);
}

long kruskal(long n, long m)
{
    long i,j,sum=0,u,v,taken=0,d=-1;
    sort(graph,graph+top);
    //for(i=0;i<m;i++) cout<<graph[i].w<<" ";
    //cout<<endl;
    for(i=0;i<=n;i++) par[i]=i;
    for(i=0; i<m; i++){
        u = parent(graph[i].u);
        v = parent(graph[i].v);
        if(u!=v){
            par[u]=v;
            sum+=graph[i].w;
            taken++;
            //cout<<"="<<graph[i].w<<endl;
        }
        else d=i;
    }
    if(d!=-1){
        //cout<<"remove = "<<graph[d].u<<" "<<graph[d].v<<" "<<graph[d].w<<endl;
        top--;
        graph[d] = graph[top];
    }
    if(taken == n-1) return sum;
    return -1;
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,ap,u,v,w;
    inLong(test);
    while(test--){
        Case(cs);
        Line();
        inLong2(n,m);
        top=0;
        for(i=0;i<m;i++){
            info in;
            inLong3(in.u,in.v,in.w);
            graph[top++] = in;
            long ans = kruskal(n,top);
            //cout<<ans<<endl;

            printf("%ld\n",ans);
        }
    }
    return 0;
}


