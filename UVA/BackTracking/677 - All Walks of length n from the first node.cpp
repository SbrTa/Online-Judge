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

long v[12][12],taken[12],l,n,f;
vector<long>p;

void call()
{
    if(p.size()==l+1){
        f=1;
        printf("(%ld",p[0]);
        FOR(i,1,l) printf(",%ld",p[i]);
        printf(")\n");
        return;
    }
    FOR(i,1,n){
        long a = p[p.size()-1];
        if(v[a][i] && !taken[i]){
            taken[i] = 1;
            p.push_back(i);
            call();
            taken[i] = 0;
            p.pop_back();
        }
    }
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    long a,b;
    do{
        if(cs>1) Line();
        cs++;
        f=0;
        scanf("%ld%ld",&n,&l);
        FOR(i,1,n) FOR(j,1,n) scanf("%ld",&v[i][j]);
        p.clear();
        mset(taken,0);
        taken[1]=1;
        p.push_back(1);
        call();
        if(f==0) printf("no walk of length %ld\n",l);
    }while(scanf("%ld",&test)==1 && test==-9999);
    return 0;
}


