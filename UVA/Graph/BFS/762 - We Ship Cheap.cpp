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

vector<long>v[10000];
long visited[10000],par[10000];

void bfs(long s, long d, long n){
    queue<long>q;
    long i;
    for(i=0;i<=n;i++){
        visited[i]=0;
        par[i]=i;
    }
    q.push(s);
    visited[i]=1;
    while(!q.empty()){
        long a = q.front();
        long sz = v[a].size();
        for(i=0;i<sz;i++){
            long b = v[a][i];
            if(!visited[b]){
                visited[b]=1;
                par[b]=a;
                q.push(b);
                if(b==d) return;
            }
        }
        q.pop();
    }
}

int main()
{
    long test,cs=1;
    long n,m,i,j,index=1;
    while(inLong(n)==1){
        for(i=0;i<=index;i++) v[i].clear();
        string a,b;
        map<string,long>mp;
        map<long,string>mmp;
        index=1;
        while(n--){
            cin>>a>>b;
            if(!mp[a]){
                mp[a]=index;
                mmp[index]=a;
                index++;
            }
            if(!mp[b]){
                mp[b]=index;
                mmp[index]=b;
                index++;
            }
            v[mp[a]].push_back(mp[b]);
            v[mp[b]].push_back(mp[a]);
        }
        cin>>a>>b;
        if(!cs) Line();
        cs=0;
        long x = mp[a];
        long y = mp[b];
        bfs(y,x,index);
        if(visited[x]){
            cout<<mmp[x]<<" "<<mmp[par[x]]<<endl;
            while(par[x]!=mp[b]){
                x=par[x];
                cout<<mmp[x]<<" "<<mmp[par[x]]<<endl;
                //cout<<x<<" "<<par[x]<<endl;
            }
        }
        else printf("No route\n");
    }
    return 0;
}

