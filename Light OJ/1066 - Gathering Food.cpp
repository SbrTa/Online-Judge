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

string g[15];
long n,visited[15][15];

struct point
{
    long x,y;
};

long valid(long x, long y, char last)
{
    if(visited[x][y]) return 0;
    if(x<0 || x>=n) return 0;
    if(y<0 || y>=n) return 0;
    if(g[x][y]=='#') return 0;
    if(g[x][y]>='A' && g[x][y]<='Z')
        if(g[x][y]>last) return 0;
    return 1;
}

long bfs(point p, char last)
{
    long i,j,cost[15][15];
    for(i=0;i<=n;i++) for(j=0;j<=n;j++) { cost[i][j]=0; visited[i][j]=0; }
    queue<point>q;
    q.push(p);
    visited[p.x][p.y]=1;
    while(!q.empty()){
        point v,u = q.front();
        long x,y;

        x=u.x;
        y=u.y+1;
        if(valid(x,y,last)){
            visited[x][y]=1;
            cost[x][y] = cost[u.x][u.y] + 1;
            v.x=x;
            v.y=y;
            q.push(v);
            if(g[x][y]==last) return cost[x][y];
        }
        x=u.x;
        y=u.y-1;
        if(valid(x,y,last)){
            visited[x][y]=1;
            cost[x][y] = cost[u.x][u.y] + 1;
            v.x=x;
            v.y=y;
            q.push(v);
            if(g[x][y]==last) return cost[x][y];
        }

        x=u.x+1;
        y=u.y;
        if(valid(x,y,last)){
            visited[x][y]=1;
            cost[x][y] = cost[u.x][u.y] + 1;
            v.x=x;
            v.y=y;
            q.push(v);
            if(g[x][y]==last) return cost[x][y];
        }
        x=u.x-1;
        y=u.y;
        if(valid(x,y,last)){
            visited[x][y]=1;
            cost[x][y] = cost[u.x][u.y] + 1;
            v.x=x;
            v.y=y;
            q.push(v);
            if(g[x][y]==last) return cost[x][y];
        }
        q.pop();
    }
    return -1;
}

int main()
{
    long test,cs=1;
    long m,a,b,i,j;
    point let[30];
    //cout<<('C'-'A')<<endl;
    inLong(test);
    while(test--){
        inLong(n);
        for(i=0;i<n;i++)
            cin>>g[i];
        for(i=0;i<26;i++){
            let[i].x=-1;
            let[i].y=-1;
        }
        char last='A';
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(g[i][j]>='A' && g[i][j]<='Z')
                {
                    char ch=g[i][j];
                    let[ch-'A'].x=i;
                    let[ch-'A'].y=j;
                    if(ch>last) last=ch;
                }
            }
        }
        Case(cs);
        if(last=='A'){
            printf(" 0\n");
            continue;
        }
        long ans=0;
        for(i=1;i<=(last-'A');i++){
            char c = i+'A';
            long r = bfs(let[i-1],c);
            if(r==-1){
                ans=-1;
                break;
            }
            else ans+=r;
        }
        if(ans==-1) printf(" Impossible\n");
        else printf(" %ld\n",ans);
    }
    return 0;
}

