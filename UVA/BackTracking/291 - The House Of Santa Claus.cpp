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

long taken[10][10],v[10][10];
vector<long>p;

void call()
{
    if(p.size()==9)
    {
        FOR(i,0,8) printf("%ld",p[i]);
        Line();
        return;
    }
    FOR(i,1,5)
    {
        long a = p[p.size()-1];
        if(v[a][i] && !taken[a][i])
        {
            taken[a][i] = taken[i][a] = 1;
            p.push_back(i);
            call();
            taken[a][i] = taken[i][a] = 0;
            p.pop_back();
        }
    }
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    v[1][2]=v[2][1]=1;
    v[1][3]=v[3][1]=1;
    v[1][5]=v[5][1]=1;
    v[2][3]=v[3][2]=1;
    v[2][5]=v[5][2]=1;
    v[3][4]=v[4][3]=1;
    v[3][5]=v[5][3]=1;
    v[4][5]=v[5][4]=1;
    //long test,cs=1;
    //long n,m,a,b;
    p.push_back(1);
    call();


    return 0;
}


