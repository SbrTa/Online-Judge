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
    bool operator < (const info & p) const{
        return w<p.w;
    }
};

vector<info>graph;
long par[111];

long parent(long r)
{
    if(par[r]==r) return r;
    return par[r]=parent(par[r]);
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
    long n,m,i,j,w;
    string a,b;
    inLong(test);
    while(test--){
        inLong(n);
        long index=1;
        map<string,long>mp;
        graph.clear();
        while(n--){
            cin>>a>>b>>w;
            if(!mp[a]) mp[a]=index++;
            if(!mp[b]) mp[b]=index++;
            info x;
            x.u=mp[a];
            x.v=mp[b];
            x.w=w;
            graph.push_back(x);
        }
        long ans = mst(index);
        for(i=2;i<index;i++){
            if(parent(i)!=parent(i-1)){
                ans=-1;
                break;
            }
        }
        Case(cs);
        if(ans==-1) printf(" Impossible\n");
        else printf(" %ld\n",ans);
    }
    return 0;
}

