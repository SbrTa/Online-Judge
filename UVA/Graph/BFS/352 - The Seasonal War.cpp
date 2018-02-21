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

int visit[100][100],flag[100][100],n,x=3;
int start_row,start_col,end_row,end_col,row,col;

struct info{
    int rr,cc;
}node;

int valid(int r, int c){
    if(r<0 || r>=n || c<0 || c>=n) return 0;
    return 1;
}

void bfs(int row, int col){
    queue<info>q;
    int i,j,r,c;
    node.rr = row;
    node.cc = col;
    q.push(node);
    while(!q.empty()){
        node = q.front();
        row = node.rr;
        col = node.cc;
//***************************************//
        r = row+1;
        c = col;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row+1;
        c = col+1;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row+1;
        c = col-1;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
//***************************************//
        r = row-1;
        c = col;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row-1;
        c = col+1;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row-1;
        c = col-1;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
//***************************************//
        r = row;
        c = col+1;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        r = row;
        c = col-1;
        if(valid(r,c) && !visit[r][c] && flag[r][c]==1){
            visit[r][c] = 1;
            flag[r][c] = 2;
            node.rr = r;
            node.cc = c;
            q.push(node);
        }
        q.pop();
    }
}

int main(){
    int m,i,j,r,c,cs=1;
    string s;
    while(inI(n)==1){
        for(i=0;i<n;i++){
            cin>>s;
            for(j=0;j<n;j++){
                if(s[j] == '0') flag[i][j] = 0;
                else flag[i][j] = 1;
                visit[i][j] = 0;
            }
        }

        int ans=0;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(flag[i][j]==1 && !visit[i][j]){
                    //++x;
                    //cout<<x<<endl;
                    bfs(i,j);
                    /*cout<<endl<<endl;
                    for(int ii=0;ii<n;ii++)
                    {
                        for(int jj=0;jj<n;jj++)
                            cout<<flag[ii][jj];
                        cout<<endl;
                    }*/
                    ans++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",cs++,ans);
    }

    return 0;
}


