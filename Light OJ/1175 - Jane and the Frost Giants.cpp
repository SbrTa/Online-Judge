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
#define inInt2(n,m) scanf("%d%d",&n,&m)
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

#define inf 9999999
#define MX 111
#define PI acos(-1.0)
using namespace std;

int moveX[] = {1, -1,  0,  0};
int moveY[] = {0,  0,  1, -1};
long r,c,jane[202][202],fire[202][202];
string s[202];

struct point
{
    long x,y;
};

int validFire(int x, int y)
{
    if(x<0 || y<0 || x>=r || y>=c || s[x][y]=='#' || fire[x][y]!=inf) return 0;
    return 1;
}

int valid(int x, int y)
{
    if(x<0 || y<0 || x>=r || y>=c || s[x][y]=='#' || jane[x][y]!=inf) return 0;
    return 1;
}

void janeBFS()
{
    long i,j,x,y;
    point p,u,v;
    queue<point>q;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(s[i][j]=='J') p.x=i, p.y=j;
            jane[i][j]=inf;
        }
    }
    q.push(p);
    jane[p.x][p.y]=1;
    while(!q.empty()){
        u = q.front();
        for(i=0;i<4;i++){
            x = u.x + moveX[i];
            y = u.y + moveY[i];
            if(valid(x,y)){
                jane[x][y] = jane[u.x][u.y] + 1;
                v.x = x;
                v.y = y;
                q.push(v);
            }
        }
        q.pop();
    }
}

void fireBFS()
{
    long i,j,x,y;
    point p,u,v;
    queue<point>q;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(s[i][j]=='F'){
                p.x=i;
                p.y=j;
                q.push(p);
                fire[i][j]=1;
            }
            else fire[i][j]=inf;
        }
    }
    while(!q.empty()){
        u = q.front();
        for(i=0;i<4;i++){
            x = u.x + moveX[i];
            y = u.y + moveY[i];
            if(validFire(x,y)){
                fire[x][y] = fire[u.x][u.y] + 1;
                v.x = x;
                v.y = y;
                q.push(v);
            }
        }
        q.pop();
    }
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j;
    inLong(test);
    while(test--){
        inLong2(r,c);
        for(i=0;i<r;i++)
            cin>>s[i];
        janeBFS();
        fireBFS();

        long ans=inf;
        for(i=0;i<c;i++)
            if(jane[0][i]<fire[0][i]) ans=min(ans,jane[0][i]);
        for(i=0;i<c;i++)
            if(jane[r-1][i]<fire[r-1][i]) ans=min(ans,jane[r-1][i]);
        for(i=0;i<r;i++)
            if(jane[i][0]<fire[i][0]) ans=min(ans,jane[i][0]);
        for(i=0;i<r;i++)
            if(jane[i][c-1]<fire[i][c-1]) ans=min(ans,jane[i][c-1]);
        printf("Case %ld:",cs++);
        if(ans==inf) printf(" IMPOSSIBLE\n");
        else printf(" %ld\n",ans);
    }
    return 0;
}

