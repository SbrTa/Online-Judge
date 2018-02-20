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

vector<info>graph;
long par[12002];

long parent(long r)
{
    if(par[r]==r) return r;
    return par[r] = parent(par[r]);
}

long min_st(long n)
{
    long i,j,u,v,sum=0;
    for(i=0;i<=n;i++) par[i]=i;
    sort(graph.begin(),graph.end());
    long sz = graph.size();
    for(i=0;i<sz;i++){
        u = parent(graph[i].u);
        v = parent(graph[i].v);
        if(u!=v){
            sum+=graph[i].w;
            par[u]=v;
        }
    }
    return sum;
}

long max_st(long n)
{
    long i,j,u,v,sum=0;
    for(i=0;i<=n;i++) par[i]=i;
    long sz = graph.size();
    for(i=sz-1;i>=0;i--){
        u = parent(graph[i].u);
        v = parent(graph[i].v);
        if(u!=v){
            sum+=graph[i].w;
            par[u]=v;
        }
    }
    return sum;
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,w;
    inLong(test);
    while(test--){
        inLong(n);
        info x;
        graph.clear();
        while(inLong3(x.u,x.v,x.w) && x.u+x.v+x.w>0){
            graph.push_back(x);
        }
        long Min = min_st(n);
        long Max = max_st(n);
        //cout<<min<<" "<<max<<endl;
        Case(cs);
        if((Min+Max)%2) printf(" %ld/2\n",Min+Max);
        else printf(" %ld\n",(Min+Max)/2);
    }

    return 0;
}

