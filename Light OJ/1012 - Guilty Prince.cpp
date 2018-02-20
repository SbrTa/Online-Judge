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

int row,col,visited[22][22];

struct info{
    int rr,cc;
}node;

int valid(int r, int c){
    if(r<0 || c<0 || r>=row || c>=col) return 0;
    return 1;
}

int bfs(){
    queue<info>q;
    int i,j,cnt=0;
    q.push(node);
    visited[node.rr][node.cc] = 1;
    while(!q.empty()){
        node = q.front();
        int rr = node.rr;
        int cc = node.cc;
        int r,c;
//***************************************//
        r = rr+1;
        c = cc;
        if(valid(r,c) && !visited[r][c]){
            visited[r][c] = 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = rr-1;
        c = cc;
        if(valid(r,c) && !visited[r][c]){
            visited[r][c] = 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
//***************************************//
        r = rr;
        c = cc+1;
        if(valid(r,c) && !visited[r][c]){
            visited[r][c] = 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = rr;
        c = cc-1;
        if(valid(r,c) && !visited[r][c]){
            visited[r][c] = 1;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        q.pop();
        cnt++;
    }
    return cnt;
}

int main()
{
    int test,cs=1;
    int n,m,a,b,i,j;
    inI(test);
    while(test--){
        inI(col);
        inI(row);
        string s;
        for(i=0;i<row;i++){
            cin>>s;
            for(j=0;j<col;j++){
                if(s[j]=='.') visited[i][j] = 0;
                else if(s[j]=='#') visited[i][j] = 2;
                else if(s[j]=='@'){
                    visited[i][j] = 0;
                    node.rr = i;
                    node.cc = j;
                }
            }
        }
        int ans = bfs();
        printf("Case %d: %d\n",cs++,ans);
    }
    return 0;
}

