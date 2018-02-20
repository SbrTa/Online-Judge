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

vector<long>v[20004];
long team[20004];

long bfs(long s){
    queue<long>q;
    long i,j,vam=0,lyc=0;
    q.push(s);
    team[s]=1;
    vam++;
    while(!q.empty()){
        long a = q.front();
        long sz = v[a].size();
        for(i=0;i<sz;i++){
            long b = v[a][i];
            if(!team[b]){
                if(team[a]==1){
                    team[b]=2;
                    lyc++;
                }
                else if(team[a]==2){
                    team[b]=1;
                    vam++;
                }
                q.push(b);
            }
        }
        q.pop();
    }
    return max(vam,lyc);
}

int main(){
    long test,cs=1;
    long n,m,a,b,i,j,s;
    inLong(test);
    while(test--){
        map<long,long>mp;
        vector<long>source;
        for(i=0;i<=20000;i++){
            v[i].clear();
            team[i]=0;
        }
        inLong(n);
        while(n--){
            inLong(a);
            inLong(b);
            v[a].push_back(b);
            v[b].push_back(a);
            if(!mp[a]){
                source.push_back(a);
                mp[a]=1;
            }
            if(!mp[b]){
                source.push_back(b);
                mp[b]=1;
            }
        }
        long ans=0;
        for(i=0;i<source.size();i++){
            if(!team[source[i]])
                ans+=bfs(source[i]);
        }
        Case(cs);
        pLong(ans);
        Line();
    }
    return 0;
}

