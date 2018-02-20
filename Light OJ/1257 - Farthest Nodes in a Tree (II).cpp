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

#define MX 111
#define PI acos(-1.0)
#define inf 10000+10000
using namespace std;

vector<long>g[30001],cost[30001];
long s,d1[30001],d2[30001];

struct node{
    long u,w;
    node(long a, long b){
        u=a;
        w=b;
    }
};

void bfs(long n)
{
    long u,v,i,j,d[n+1],mx=-1,visited[n+1];
    for(i=0;i<n;i++)
        visited[i]=0;
    queue<node>q;
    q.push(node(s,0));
    d1[s]=0;
    visited[s]=1;
    while(!q.empty()){
        node top = q.front();
        u = top.u;
        long sz = g[u].size();
        for(i=0;i<sz;i++){
            v = g[u][i];
            if(!visited[v]){
                visited[v]=1;
                d1[v] = d1[u] + cost[u][i];
                q.push(node(v,d1[v]));
                if(d1[v]>mx){
                    mx = d1[v];
                    s = v;
                }
            }
        }
        //cout<<u<<endl;
        q.pop();
    }
}

void bfs2(long n)
{
    long u,v,i,j,d[n+1],mx=-1,visited[n+1];
    for(i=0;i<n;i++)
        visited[i]=0;
    queue<node>q;
    q.push(node(s,0));
    d2[s]=0;
    visited[s]=1;
    while(!q.empty()){
        node top = q.front();
        u = top.u;
        long sz = g[u].size();
        for(i=0;i<sz;i++){
            v = g[u][i];
            if(!visited[v]){
                visited[v]=1;
                d2[v] = d2[u] + cost[u][i];
                q.push(node(v,d2[v]));
                if(d2[v]>mx){
                    mx = d2[v];
                    s = v;
                }
            }
        }
        //cout<<u<<endl;
        q.pop();
    }
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,w,mx;
    inLong(test);
    while(test--){
        inLong(n);
        for(i=0;i<n;i++){
            g[i].clear();
            cost[i].clear();
        }
        for(i=1;i<n;i++){
            inLong2(a,b);
            inLong(w);
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a].push_back(w);
            cost[b].push_back(w);
            s=b;
        }
        bfs(n);
        bfs(n);
        bfs2(n);
        Case(cs);
        Line();
        for(i=0;i<n;i++)
            printf("%ld\n",max(d1[i],d2[i]));
    }
    return 0;
}
