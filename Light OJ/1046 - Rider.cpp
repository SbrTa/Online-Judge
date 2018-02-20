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

#define inf 99999999
#define MX 111
#define PI acos(-1.0)

long dx[] = { 1, 1,-1,-1, 2, 2,-2,-2 };
long dy[] = { 2,-2, 2,-2, 1,-1, 1,-1 };

using namespace std;

long r,c,Move[111][111],d[11][11];
string s[11];

struct point
{
    long x,y;
};

long valid(long x, long y)
{
    if(x<0 || y<0 || x>=r || y>=c || d[x][y]!=-1) return 0;
    return 1;
}

void bfs(point p)
{
    long i,j;
    for(i=0;i<=r;i++) for(j=0;j<=c;j++) d[i][j]=-1;
    queue<point>q;
    q.push(p);
    d[p.x][p.y]=0;
    while(!q.empty()){
        point v,u = q.front();
        q.pop();
        for(i=0;i<8;i++){
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];
            if(valid(v.x,v.y)){
                d[v.x][v.y] = d[u.x][u.y] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,k;
    point p;
    inLong(test);
    while(test--){
        inLong2(r,c);
        a=0;
        for(i=0;i<r;i++) cin>>s[i];
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(s[i][j]!='.'){
                    k=s[i][j]-'0';
                    p.x=i; p.y=j;
                    bfs(p);
                    b=0;
                    for(long ii=0; ii<r; ii++){
                        for(long jj=0; jj<c; jj++){
                            if(d[ii][jj]==-1)    Move[a][b++] = -1;
                            else{
                                int x=0;
                                if(d[ii][jj]%k) x = 1;
                                Move[a][b++] = d[ii][jj]/k + x;
                            }
                        }
                    }
                    a++;
                }
            }
        }
        /*for(i=0;i<a;i++){
            for(j=0;j<b;j++)
                cout<<Move[i][j]<<" ";
            cout<<endl;
        }*/

        long ans=inf;
        for(j=0;j<b;j++){
            long f=0;
            for(i=0;i<a;i++){
                if(Move[i][j]==-1){
                    f=-1;
                    break;
                }
                f+=Move[i][j];
            }
            //cout<<f<<" ";
            if(f==-1) continue;
            ans = min(ans,f);
            //cout<<ans<<endl;
        }
        Case(cs);
        if(ans==inf) printf(" -1\n");
        else printf(" %ld\n",ans);
    }
    return 0;
}

