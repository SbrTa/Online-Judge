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

vector<int>v[202];
int visited[202];
int source,n;

void visit(int a, int b){
    if(visited[a]==1) visited[b]=2;
    if(visited[a]==2) visited[b]=1;
}

void bfs(){
    queue<int>q;
    int i,j;
    for(i=0;i<=n;i++) visited[i]=0;
    q.push(source);
    visited[source] = 1;
    while(!q.empty()){
        int a = q.front();
        int sz = v[a].size();
        for(i=0;i<sz;i++){
            int b = v[a][i];
            if(visited[a] == visited[b]){
                printf("NOT BICOLORABLE.\n");
                return;
            }
            if(!visited[b]){
                visit(a,b);
                q.push(b);
            }
        }
        q.pop();
    }
    printf("BICOLORABLE.\n");
    return;
}

int main(){
    int test,cs=1;
    int m,a,b,i,j;
    while(inI(n) && n){
        for(i=0;i<=n;i++) v[i].clear();
        inI(m);
        while(m--){
            inI(a);
            inI(b);
            v[a].push_back(b);
            v[b].push_back(a);
            source = a;
        }
        bfs();
    }
    return 0;
}

