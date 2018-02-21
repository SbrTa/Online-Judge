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

long graph[111][111],n,m,in[111],sol[111],s;

void topSort()
{
    long i,j,u,v;
    s=0;
    queue<long>q;
    for(i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(!q.empty()){
        u = q.front();
        q.pop();
        sol[s++]=u;
        for(v=1;v<=n;v++){
            if(graph[u][v]){
                graph[u][v]=0;
                in[v]--;
                if(!in[v]) q.push(v);
            }
        }
    }
}

int main()
{
    long test,cs=1;
    long a,b,i,j;
    while(inLong2(n,m)==2 && n+m){
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++) graph[i][j]=0;
            in[i]=0;
        }
        while(m--){
            inLong2(a,b);
            graph[a][b]=1;
            in[b]++;
        }
        topSort();
        if(s) printf("%ld",sol[0]);
        for(i=1;i<s;i++) printf(" %ld",sol[i]);
        Line();
    }
    return 0;
}
