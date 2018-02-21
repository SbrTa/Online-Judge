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

int visit[1003][1003];
int start_row,start_col,end_row,end_col,row,col;

struct info{
    int rr,cc;
}node;

int valid(int r, int c){
    if(r<0 || r>=row || c<0 || c>=col) return 0;
    return 1;
}

int bfs(){
    queue<info>q;
    int d[row+1][col+1];
    int i,j;
    for(i=0;i<=row;i++){
        for(j=0;j<=col;j++)
            d[i][j]=0;
    }
    node.rr = start_row;
    node.cc = start_col;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        int r = node.rr;
        int c = node.cc;
        if(valid(r+1,c) && !visit[r+1][c]){
            visit[r+1][c] = 1;
            d[r+1][c] = d[r][c] + 1;
            node.rr = r+1;
            node.cc = c;
            q.push(node);
        }
        if(valid(r-1,c) && !visit[r-1][c]){
            visit[r-1][c] = 1;
            d[r-1][c] = d[r][c] + 1;
            node.rr = r-1;
            node.cc = c;
            q.push(node);
        }
        if(valid(r,c+1) && !visit[r][c+1]){
            visit[r][c+1] = 1;
            d[r][c+1] = d[r][c] + 1;
            node.rr = r;
            node.cc = c+1;
            q.push(node);
        }
        if(valid(r,c-1) && !visit[r][c-1]){
            visit[r][c-1] = 1;
            d[r][c-1] = d[r][c] + 1;
            node.rr = r;
            node.cc = c-1;
            q.push(node);
        }
        if(d[end_row][end_col]) return d[end_row][end_col];
        q.pop();
    }
    return d[end_row][end_col];
}

int main(){
    int n,m,i,j,r,c;
    while(inI(row) && inI(col)){
        if(!row && !col) break;
        for(i=0;i<=row;i++){
            for(j=0;j<=col;j++)
                visit[i][j]=0;
        }
        inI(n);
        while(n--)
        {
            inI(r);
            inI(m);
            while(m--){
                inI(c);
                visit[r][c]=1;
            }
        }
        inI(start_row);
        inI(start_col);
        inI(end_row);
        inI(end_col);
        int ans = bfs();
        pI(ans);
        pLine();
    }

    return 0;
}

