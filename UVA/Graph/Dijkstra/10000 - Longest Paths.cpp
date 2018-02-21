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
long d[111];

void dijkstra(long n, long src)
{
    long i,j,u,v;
    queue<long>q;
    q.push(src);
    d[src]=0;
    while(!q.empty()){
        u = q.front();
        q.pop();
        long sz = graph[u].size();
        for(i=0;i<sz;i++){
            v = graph[u][i];
            if(d[v]<d[u]+1){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,src;
    while(inLong(n) && n){
        inLong(src);
        for(i=0;i<=n;i++){
            graph[i].clear();
            d[i]=0;
        }
        while(inLong2(a,b) && a+b){
            graph[a].push_back(b);
        }
        dijkstra(n,src);
        long mx=-1,node;
        for(i=1;i<=n;i++){
            if(d[i]>mx){
                mx=d[i];
                node=i;
            }
        }
        printf("Case %ld: The longest path from %ld has length %ld, finishing at %ld.\n\n",cs++,src,mx,node);
    }
    return 0;
}

