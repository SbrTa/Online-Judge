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
long par[10004];

long parent(long r)
{
    if(par[r]==r) return r;
    return par[r] = parent(par[r]);
}

long kruskal(long m, long ap)
{
    long i,j,sum=0,u,v;
    for(i=0; i<m && graph[i].w<ap; i++){
        u = parent(graph[i].u);
        v = parent(graph[i].v);
        if(u!=v){
            par[u]=v;
            sum+=graph[i].w;
            //cout<<"="<<graph[i].w<<endl;
        }
    }
    return sum;
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,ap,u,v,w;
    inLong(test);
    while(test--){
        inLong3(n,m,ap);
        graph.clear();
        for(i=0;i<=n;i++) par[i]=i;
        for(i=0;i<m;i++){
            info in;
            inLong3(in.u,in.v,in.w);
            graph.push_back(in);
        }
        sort(graph.begin(),graph.end());
        long ans = kruskal(m,ap),cnt=0;
        //cout<<ans<<endl;
        for(i=1;i<=n;i++){
            if(parent(i)==i){
                ans+=ap;
                cnt++;
            }
        }
        Case(cs);
        printf(" %ld %ld\n",ans,cnt);
    }
    return 0;
}

