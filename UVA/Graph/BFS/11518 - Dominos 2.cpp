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

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;

vector<long>v[10011];
long par[10011];

void bfs(long s)
{
    queue<long>q;
    long i,j;
    q.push(s);
    par[s]=1;
    while(!q.empty()){
        long a = q.front();
        long sz = v[a].size();
        for(i=0;i<sz;i++){
            long b = v[a][i];
            if(!par[b]){
                par[b]=1;
                q.push(b);
            }
        }
        q.pop();
    }
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,l;
    inLong(test);
    while(test--){
        inLong(n);
        inLong(m);
        inLong(l);
        for(i=1;i<=n;i++){
            v[i].clear();
            par[i]=0;
        }
        while(m--){
            inLong(a);
            inLong(b);
            v[a].push_back(b);
        }
        while(l--){
            inLong(a);
            if(!par[a]) bfs(a);
        }
        long ans=0;
        for(i=1;i<=n;i++)
            if(par[i]) ans++;
        pLong(ans);
        Line();
    }
    return 0;
}

