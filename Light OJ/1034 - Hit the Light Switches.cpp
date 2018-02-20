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
#define inLL(n) scanf("%lld",&n)
#define inFloat(n) scanf("%f",&n)
#define inDouble(n) scanf("%lf",&n)
#define inLD(n) scanf("%Lf",&n)
#define inStr(n) scanf("%s",n)
#define inChar(n) scanf("%c",&n)

#define pInt(n) printf("%d",n)
#define pLong(n) printf("%ld",n)
#define pLL(n) printf("%lld",n)
#define pFloat(n) printf("%f",n)
#define pDouble(n) printf("%lf",n)
#define pLD(n) printf("%Lf",n)
#define pStr(n) printf("%s",n)
#define pSpc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld: ",n++)

#define INF 10000+11
#define MX 111
#define PI acos(-1.0)
using namespace std;

long n,color[INF];;
vector<long>graph[INF],solve;

void visit(long u)
{
    long i,j,v,sz;
    color[u]=1;
    sz = graph[u].size();
    for(i=0;i<sz;i++){
        v=graph[u][i];
        if(color[v]==0)
            visit(v);
    }
    solve.push_back(u);
}

void dfs()
{
    long i,j=0;
    solve.clear();
    for(i=1;i<=n;i++){
        if(color[i]==0)
            visit(i);
    }
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    long m,a,b,i,j,l;
    inLong(test);
    while(test--){
        inLong(n);
        inLong(m);
        for(i=1;i<=n;i++){
            graph[i].clear();
            color[i] = 0;
        }
        while(m--){
            inLong(a);
            inLong(b);
            graph[a].push_back(b);
        }
        dfs();
        long ans=0;
        for(i=1;i<=n;i++) color[i] = 0;
        for(i=solve.size()-1; i>=0; i--){
            if(color[solve[i]]==0){
                ans++;
                visit(solve[i]);
            }
        }
        Case(cs);
        pLong(ans);
        Line();
    }
    return 0;
}


/*
1
7 6
1 2
2 3
4 5
5 6
7 1
7 4
*/
