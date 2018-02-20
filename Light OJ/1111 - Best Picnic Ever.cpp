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

vector<long>g[1111];
long cnt[1111],n;

void bfs(long s)
{
    long i,j,visited[n+1],u,v;
    for(i=1;i<=n;i++) visited[i]=0;
    queue<long>q;
    q.push(s);
    visited[s]=1;
    cnt[s]++;
    while(!q.empty()){
        u = q.front();
        long sz = g[u].size();
        for(i=0;i<sz;i++){
            v = g[u][i];
            if(!visited[v]){
                visited[v]=1;
                cnt[v]++;
                q.push(v);
            }
        }
        q.pop();
    }
}

int main()
{
    long test,cs=1;
    long m,a,b,i,j,man,mc[111];
    inLong(test);
    while(test--){
        inLong(man);
        inLong2(n,m);
        for(i=0;i<man;i++) inLong(mc[i]);
        for(i=1;i<=n;i++){
            g[i].clear();
            cnt[i]=0;
        }
        for(i=0;i<m;i++){
            inLong2(a,b);
            g[a].push_back(b);
        }
        for(i=0;i<man;i++){
            bfs(mc[i]);
        }
        long ans=0;
        for(i=1;i<=n;i++)
            if(cnt[i]==man) ans++;
        Case(cs);
        printf(" %ld\n",ans);
    }
    return 0;
}

