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
long par[55];

long parent(long r)
{
    if(par[r]==r) return r;
    return par[r] = parent(par[r]);
}

long mst(long n)
{
    long i,j,u,v,sum=0;
    for(i=0;i<=n;i++) par[i]=i;
    sort(graph.begin(),graph.end());
    long sz=graph.size();
    for(i=0;i<sz;i++){
        u = parent(graph[i].u);
        v = parent(graph[i].v);
        if(u!=v){
            par[u]=v;
            sum+=graph[i].w;
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
        graph.clear();
        long total=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                inLong(w);
                total+=w;
                info x;
                x.u=i;
                x.v=j;
                x.w=w;
                if(w!=0) graph.push_back(x);
            }
        }
        //cout<<mst(n)<<endl;
        long ans = total - mst(n);
        Case(cs);
        for(i=1;i<n;i++){
            if(parent(i)!=parent(i-1)){
                ans=-1;
                break;
            }
        }
        printf(" %ld\n",ans);
    }
    return 0;
}

