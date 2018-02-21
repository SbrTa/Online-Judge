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

#define INF 111
#define MX 111
#define PI acos(-1.0)
using namespace std;

long start_row,start_col,end_row,end_col;

struct info{
    long rr,cc;
}node;

int valid(long r, long c){
    if(r<1 || c<1 || r>8 || c>8) return 0;
    return 1;
}

long bfs(){
    queue<info>q;
    long visit[10][10],d[10][10],i,j;
    for(i=0;i<=8;i++){
        for(j=0;j<=8;j++)
            visit[i][j] = d[i][j] = 0;
    }
    node.rr = start_row;
    node.cc = start_col;
    q.push(node);
    visit[start_row][start_col] = 1;
    while(!q.empty()){
        node = q.front();
        long row = node.rr;
        long col = node.cc;
        long r,c;
//************************************//
        r = row+2;
        c = col+1;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row+2;
        c = col-1;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
//************************************//
        r = row-2;
        c = col+1;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row-2;
        c = col-1;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
//************************************//
        r = row+1;
        c = col+2;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row-1;
        c = col+2;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
//************************************//
        r = row+1;
        c = col-2;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row-1;
        c = col-2;
        if(valid(r,c) && !visit[r][c]){
            visit[r][c] = 1;
            d[r][c] = d[row][col] + 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        if(d[end_row][end_col]) return d[end_row][end_col];
        q.pop();
    }
    return d[end_row][end_col];
}

int main(){
    long test,cs=1;
    long n,m,i,j;
    string a,b;
    while(cin>>a>>b){
        start_row = a[0] - 'a' + 1;
        start_col = a[1] - '0';
        end_row   = b[0] - 'a' + 1;
        end_col   = b[1] - '0';
        long ans = bfs();
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<ans<<" knight moves.\n";
    }
    return 0;
}
