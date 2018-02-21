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
#define Spc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld: ",n++)

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;

vector<long>v[2510];
long par[2510];

void bfs(long s, long n){
    queue<long>q;
    long visited[n+1],i;
    for(i=0;i<=n;i++){
        visited[i]=0;
        par[i]=-1;
    }
    q.push(s);
    visited[s]=1;
    par[s]=0;
    long day=1;
    while(!q.empty()){
        long a=q.front();
        long sz=v[a].size();
        for(i=0;i<sz;i++){
            long b=v[a][i];
            if(!visited[b]){
                visited[b]=1;
                par[b] = par[a]+1;
                q.push(b);
            }
        }
        q.pop();
    }
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j;
    while(inLong(n)==1){
        for(i=0;i<n;i++){
            v[i].clear();
            inLong(m);
            while(m--){
                inLong(a);
                v[i].push_back(a);
            }
        }
        inLong(m);
        while(m--){
            inLong(a);
            bfs(a,n);
            //for(i=0;i<n;i++) cout<<par[i]<<" ";
            //cout<<endl;
            long nn[n+1];
            for(i=0;i<n;i++) nn[i]=0;
            for(i=0;i<n;i++){
                nn[par[i]]++;
            }
            //for(i=0;i<n;i++) cout<<nn[i]<<" ";
            //cout<<endl;
            long mx=0,ind=0;
            for(i=1;i<n;i++){
                if(nn[i]>mx){
                    mx=nn[i];
                    ind=i;
                }
            }
            if(mx==0) pLong(mx);
            else
                pLong(mx),Spc(),pLong(ind);
            Line();
        }
    }
    return 0;
}

