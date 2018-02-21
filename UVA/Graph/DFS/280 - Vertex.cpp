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

vector<long>graph[111];
long color[111];

void dfs(long u)
{
    long i,j,v,sz;
    sz=graph[u].size();
    color[u]++;
    for(i=0;i<sz;i++){
        v=graph[u][i];
        if(!color[v])
            dfs(v);
    }
}


int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    long n,m,a,b,i,j;
    while(inLong(n) && n){
        for(i=0;i<=n;i++)
            graph[i].clear();
        while(inLong(a) && a){
            while(inLong(b) && b)
                graph[a].push_back(b);
        }
        inLong(m);
        while(m--){
            inLong(a);
            for(i=0;i<=n;i++) color[i]=0;
            color[a]=-1;
            dfs(a);
            long x=0;
            for(i=1;i<=n;i++) if(!color[i]) x++;
            printf("%ld",x);
            for(i=1;i<=n;i++) if(!color[i]) printf(" %ld",i);
            Line();
        }
    }
    return 0;
}

/*
3
1 2 0
2 2 0
3 1 2 0
0
2 1 2
*/
