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

vector<long>graph[20002];
long n,taken[20002],in[20002];

void topSort()
{
    long i,j,u,v;
    queue<long>q;
    for(i=1;i<n;i++){
        if(!in[i]){
            q.push(i);
            taken[i]=1;
        }
    }
    while(!q.empty()){
        u = q.front();
        q.pop();
        long sz = graph[u].size();
        for(i=0;i<sz;i++){
            v = graph[u][i];
            in[v]--;
            if(!in[v]){
                q.push(v);
                taken[v]=1;
            }
        }
    }
}

int main()
{
    long test,cs=1;
    long m,i,j;
    inLong(test);
    while(test--){
        for(i=0;i<=n;i++){
            graph[i].clear();
            taken[i]=0;
            in[i]=0;
        }
        inLong(m);
        map<string,long>mp;
        string a,b;
        n=1;
        while(m--){
            cin>>a>>b;
            if(!mp[a]) mp[a]=n++;
            if(!mp[b]) mp[b]=n++;
            graph[mp[a]].push_back(mp[b]);
            in[mp[b]]++;
        }
        topSort();
        int ans = 1;
        for(i=1;i<n;i++){
            if(!taken[i]){
                ans=0;
                break;
            }
        }
        Case(cs);
        if(ans) printf(" Yes\n");
        else printf(" No\n");
    }
    return 0;
}

