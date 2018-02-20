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

vector<long>g[1111],prime;

void seive()
{
    long i,j;
    bool check[1100];
    for(i=3;i<=1100;i+=2)
        check[i]=true;
    for(i=3;i*i<=1100;i+=2)
    {
        if(check[i]==true)
        {
            for(j=i*i;j<=1100;j+=i+i)
                check[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3;i<=1100;i+=2)
    {
        if(check[i]==true)
            prime.push_back(i);
    }
}

long bfs(long s, long t)
{
    long u,v,i,j,visited[t+5],cost[t+5];
    for(i=0;i<=t;i++){
        visited[i]=0;
        cost[i]=0;
    }
    queue<long>q;
    q.push(s);
    visited[s]=1;
    while(!q.empty()){
        u = q.front();
        long yes=0;
        for(i=0;i<g[u].size();i++){
            v = u+g[u][i];
            if(visited[v]==0 && v<=t){
                visited[v]=1;
                cost[v]=cost[u]+1;
                //cout<<v<<" "<<cost[v]<<endl;
                if(v==t) return cost[v];
                q.push(v);
            }
        }
        q.pop();
    }
    return 0;
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,s,t;
    seive();
    //for(i=0;i<10;i++) cout<<prime[i]<<" ";
    for(n=2;n<=1001;n++){
        for(i=0;prime[i]<n;i++)
            if(n%prime[i]==0) g[n].push_back(prime[i]);
    }
    //cout<<"start\n";

    inLong(test);
    while(test--){
        inLong2(s,t);
        long ans = bfs(s,t);
        Case(cs);
        if(s==t){
            printf(" 0\n");
            continue;
        }
        if(ans) printf(" %ld\n",ans);
        else printf(" -1\n");
    }
    return 0;
}

