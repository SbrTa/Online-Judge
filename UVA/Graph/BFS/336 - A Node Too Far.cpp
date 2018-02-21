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

#define inI(n) scanf("%d",&n)
#define inL(n) scanf("%ld",&n)
#define inLL(n) scanf("%lld",&n)
#define inF(n) scanf("%f",&n)
#define inD(n) scanf("%lf",&n)
#define inLD(n) scanf("%Lf",&n)
#define inStr(n) scanf("%s",n)
#define inC(n) scanf("%c",&n)

#define pI(n) printf("%d",n)
#define pL(n) printf("%ld",n)
#define pLL(n) printf("%lld",n)
#define pF(n) printf("%f",n)
#define pD(n) printf("%lf",n)
#define pLD(n) printf("%Lf",n)
#define pStr(n) printf("%s",n)
#define pSpc(n) printf(" ")
#define pLine(n) printf("\n")

#define Set(a,n) memset(a,n,sizeof(a))
#define pb push_back
#define INF 11111111
#define MX 111
#define PI acos(-1.0)
using namespace std;

vector<long>v[50];
long ttl,source;

void vclear(){
    for(int i=0;i<50;i++) v[i].clear();
}

long bfs(long n){
    long i,j,visit[50],d[50],cnt=0;
    queue<long>q;
    Set(visit,0);
    Set(d,0);
    q.push(source);
    visit[source]=1;
    while(!q.empty()){
        long u = q.front();
        long sz = v[u].size();
        for(i=0;i<sz;i++){
            long x = v[u][i];
            if(visit[x]==0){
                d[x] = d[u]+1;
                q.push(x);
                visit[x] = 1;
            }
        }
        q.pop();
    }
    for(i=1;i<=n;i++){
        //cout<<d[i]<<endl;
        if(visit[i] && d[i]<=ttl)   cnt++;
    }
    return n-cnt;
}

int main(){
    long test,cs=1;
    long n,i,j;
    string a,b,m;
    while(inL(n) && n){
        vclear();
        long index = 0;
        map<string,long>mp;
        for(i=0;i<n;i++){
            cin>>a>>b;
            if(!mp[a]) mp[a]=++index;
            if(!mp[b]) mp[b]=++index;
            v[mp[a]].pb(mp[b]);
            v[mp[b]].pb(mp[a]);
        }
        while(1){
            cin>>m;
            source = mp[m];
            inL(ttl);
            if(source==0 && ttl==0) break;
            printf("Case %ld: %ld nodes not reachable from node ",cs++,bfs(mp.size()));
            cout<<m;
            printf(" with TTL = %ld.\n",ttl);
        }
    }
    return 0;
}

