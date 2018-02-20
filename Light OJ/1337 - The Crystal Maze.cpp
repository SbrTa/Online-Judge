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

string s[555];
long m,n,visited[555][555];

struct point
{
    long x,y;
};

long valid(long x,long y)
{
    if(x<0 || x>=m) return 0;
    if(y<0 || y>=n) return 0;
    if(s[x][y]=='#') return 0;
    if(visited[x][y]!=0) return 0;
    return 1;
}

long bfs(point p)
{
    long i,j,cnt=0;
    queue<point>q;
    q.push(p);
    visited[p.x][p.y]=-1;
    if(s[p.x][p.y]=='C') cnt++;
    while(!q.empty()){
        point v,u = q.front();
        long x,y;

        x = u.x;
        y = u.y+1;
        if(valid(x,y)){
            visited[x][y]=-1;
            if(s[x][y]=='C') cnt++;
            v.x=x;
            v.y=y;
            q.push(v);
        }
        x = u.x;
        y = u.y-1;
        if(valid(x,y)){
            visited[x][y]=-1;
            if(s[x][y]=='C') cnt++;
            v.x=x;
            v.y=y;
            q.push(v);
        }

        x = u.x+1;
        y = u.y;
        if(valid(x,y)){
            visited[x][y]=-1;
            if(s[x][y]=='C') cnt++;
            v.x=x;
            v.y=y;
            q.push(v);
        }
        x = u.x-1;
        y = u.y;
        if(valid(x,y)){
            visited[x][y]=-1;
            if(s[x][y]=='C') cnt++;
            v.x=x;
            v.y=y;
            q.push(v);
        }
        q.pop();
    }
    for(i=0;i<=m;i++) for(j=0;j<=n;j++){
        if(cnt==0 && visited[i][j]==-1) visited[i][j]=-2;
        else if(visited[i][j]==-1) visited[i][j]=cnt;
    }

    return cnt;
}

int main()
{
    long test,cs=1;
    long a,b,i,j,q;
    inLong(test);
    while(test--){
        inLong2(m,n);
        inLong(q);
        for(i=0;i<m;i++){
            cin>>s[i];
        }
        for(i=0;i<=m;i++) for(j=0;j<=n;j++) visited[i][j]=0;
        Case(cs);
        Line();
        while(q--){
            inLong2(a,b);
            a--;
            b--;
            if(visited[a][b]==-2){
                printf("0\n");
                continue;
            }
            if(visited[a][b]>0){
                printf("%ld\n",visited[a][b]);
                continue;
            }
            point p;
            p.x=a; p.y=b;
            long ans = bfs(p);
            printf("%ld\n",ans);
        }
    }
    return 0;
}

