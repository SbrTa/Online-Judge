/*
If this code works, it was written by Subrata Roy.
If not, I don’t know who wrote it..
*/

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

vector<long>graph[10004];
long color[10004];

void dfs(long u)
{
    long i,j,v,sz;
    color[u]=1;
    sz=graph[u].size();
    for(i=0;i<sz;i++){
        v=graph[u][i];
        if(!color[v]) dfs(v);
    }
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    long n,m,a,b,i,j,l;
    inLong(test);
    while(test--){
        inLong3(n,m,l);
        for(i=1;i<=n;i++){
            graph[i].clear();
            color[i]=0;
        }
        while(m--){
            inLong2(a,b);
            graph[a].push_back(b);
        }
        while(l--){
            inLong(a);
            if(!color[a]) dfs(a);
        }
        long ans=0;
        for(i=1;i<=n;i++) if(color[i]) ans++;
        printf("%ld\n",ans);
    }
    return 0;
}

