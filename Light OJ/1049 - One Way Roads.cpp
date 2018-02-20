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

long cost[111][111],n,par[111];
vector<long>g[111];

long bfs()
{
    long i,j,u,v,sz,visited[n+2],c[n+2],possible[n+2][n+2];
    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++) possible[i][j]=1;
        visited[i]=0;
        c[i]=0;
    }
    queue<long>q;
    q.push(1);
    while(!q.empty()){
        u = q.front();
        sz = g[u].size();
        int x=0;
        for(i=0;i<sz && x==0;i++){
            v = g[u][i];
            if(!visited[v] && possible[u][v]){
                visited[v]=1;
                possible[v][u]=0;
                c[v] = c[u] + cost[u][v];
                par[v]=u;
                q.push(v);
                //cout<<v<<" "<<par[v]<<endl;
                x=1;
            }
        }
        q.pop();
    }
    return c[1];
}

int main()
{
    long test,cs=1;
    long m,a,b,i,j,w;
    inLong(test);
    while(test--){
        inLong(n);
        for(i=0;i<=n;i++){
            g[i].clear();
        }
        for(i=0;i<n;i++){
            inLong2(a,b);
            inLong(w);
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a][b]=0;
            cost[b][a]=w;
        }
        long y=0,x=bfs();
        //cout<<x<<endl;
        long p=1;
        while(1){
            //cout<<par[p]<<" "<<cost[p][par[p]]<<endl;
            y+=cost[p][par[p]];
            p=par[p];
            if(p==1) break;
        }
        Case(cs);
        printf(" %ld\n",min(x,y));
    }

    return 0;
}

