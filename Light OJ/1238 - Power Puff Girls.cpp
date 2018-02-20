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

string v[22];
long n,m,visited[22][22],cost[22][22];

struct point{
    long x,y;
};

long valid(long a, long b)
{
    if(visited[a][b]) return 0;
    if(a>=n || a<0) return 0;
    if(b>=m || b<0) return 0;
    return 1;
}

void bfs(point p)
{
    long i,j;
    for(i=0;i<22;i++) for(j=0;j<22;j++) cost[i][j]=0;
    queue<point>q;
    q.push(p);
    visited[p.x][p.y]=1;
    while(!q.empty()){
        point v,u = q.front();
        long a,b;

        a=u.x;
        b=u.y+1;
        if(valid(a,b)){
            visited[a][b]=1;
            cost[a][b] = cost[u.x][u.y] + 1;
            v.x=a;
            v.y=b;
            q.push(v);
        }

        a=u.x;
        b=u.y-1;
        if(valid(a,b)){
            visited[a][b]=1;
            cost[a][b] = cost[u.x][u.y] + 1;
            v.x=a;
            v.y=b;
            q.push(v);
        }

        a=u.x+1;
        b=u.y;
        if(valid(a,b)){
            visited[a][b]=1;
            cost[a][b] = cost[u.x][u.y] + 1;
            v.x=a;
            v.y=b;
            q.push(v);
        }
        a=u.x-1;
        b=u.y;
        if(valid(a,b)){
            visited[a][b]=1;
            cost[a][b] = cost[u.x][u.y] + 1;
            v.x=a;
            v.y=b;
            q.push(v);
        }
        q.pop();
    }
}

int main()
{
    long test,cs=1;
    long a,b,i,j,ax,ay,bx,by,cx,cy;
    inLong(test);
    while(test--){
        point p;
        inLong2(n,m);
        for(i=0;i<n;i++)
            cin>>v[i];
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(v[i][j]=='h'){
                    p.x=i; p.y=j;
                }
                if(v[i][j]=='a'){
                    ax=i; ay=j;
                }
                if(v[i][j]=='b'){
                    bx=i; by=j;
                }
                if(v[i][j]=='c'){
                    cx=i; cy=j;
                }

                if(v[i][j]=='m' || v[i][j]=='#')
                    visited[i][j]=1;
                else visited[i][j]=0;
            }
        }
        bfs(p);
        long ans = max(cost[ax][ay], max(cost[bx][by],cost[cx][cy]));
        Case(cs);
        printf(" %ld\n",ans);
    }
    return 0;
}

