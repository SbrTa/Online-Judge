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

#define inI(n)      scanf("%d",&n)
#define inL(n)      scanf("%ld",&n)
#define inL2(n,m)   scanf("%ld%ld",&n,&m)
#define inL3(n,m,l) scanf("%ld%ld%ld",&n,&m,&l)
#define inLL(n)     scanf("%lld",&n)
#define inLL2(n,m)  scanf("%lld%lld",&n,&m)
#define inDouble(n) scanf("%lf",&n)
#define inStr(n)    scanf("%s",n)
#define inCh(n)     scanf("%c",&n)
#define PB          push_back
#define LL          long long

#define mset(a,n)   memset(a,n,sizeof(a))
#define sortV(v)    sort(v.begin(),v.end())
#define sortA(a,n)  sort(a,a+n)
#define FOR(i,a,b)    for(long i=a;i<=b;i++)

#define Spc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld:",n++)

#define eps 10e-9
#define inf 0x7f7f7f7f
#define mod 10000007
#define MX 111
#define PI 2*acos(0.0)
using namespace std;
vector<long>v[1011];
long c[1011];

void bfs(long n)
{
    long i,j;
    for(i=0;i<=n;i++) c[i]=0;
    queue<long>q;
    q.push(0);
    while(!q.empty()){
        long a=q.front();
        long sz=v[a].size();
        for(i=0;i<sz;i++){
            long b=v[a][i];
            if(!c[b]){
                c[b]=c[a]+1;
                q.push(b);
            }
        }
        q.pop();
    }
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    long n,m,a,b,i,j;
    inL(test);
    while(test--){
        if(cs==2) puts("");
        cs=2;
        inL2(n,m);
        for(i=0;i<=n;i++) v[i].clear();
        for(i=0;i<m;i++){
            inL2(a,b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bfs(n);
        for(i=1;i<n;i++) printf("%ld\n",c[i]);
    }
    return 0;
}

