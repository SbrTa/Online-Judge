N/*
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

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;

long in[111],n,taken[111];
vector<long>graph[111];
map<string,long>mp;
map<long,string>smp;

void topSort()
{
    long i,j,u,v;
    priority_queue<long>q;
    for(i=1;i<=n;i++){
        if(!in[i]){
            q.push(-i);
            taken[i]=1;
        }
    }
    while(!q.empty()){
        u = -q.top();
        cout<<" "<<smp[u];
        q.pop();
        for(i=0;i<graph[u].size();i++){
            v = graph[u][i];
            if(!taken[v]){
                in[v]--;
                if(!in[v]){
                    q.push(-v);
                    taken[v]=1;
                }
            }
        }
    }
}

int main()
{
    long test,cs=1;
    long m,a,b,i,j;
    string u,v;
    while(inLong(n)==1){
        mp.clear();
        smp.clear();
        for(i=1;i<=n;i++){
            cin>>u;
            mp[u] = i;
            smp[i] = u;
        }
        for(i=0;i<=n;i++){
            graph[i].clear();
            in[i]=0;
            taken[i]=0;
        }
        inLong(m);
        while(m--){
            cin>>u>>v;
            graph[mp[u]].push_back(mp[v]);
            in[mp[v]]++;
        }
        printf("Case #%ld: Dilbert should drink beverages in this order:",cs++);
        topSort();
        printf(".\n\n");
    }

    return 0;
}

