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
#define rFOR(i,a,b)   for(long i=a;i>=b;i--)

#define Spc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld:",n++)

#define eps 10e-9
#define inf 0x7f7f7f7f
#define mod 10000007
#define MX 111
#define PI 2*acos(0.0)
using namespace std;

vector<long>v;
long n,taken[16+1],p[35];

void call()
{
    if(v.size()==n-1){
        if(!p[v[v.size()-1]+1]) return;
        printf("1");
        FOR(i,0,v.size()-1) printf(" %ld",v[i]);
        Line();
        //printf("1");
        //rFOR(i,v.size()-1,0) printf(" %ld",v[i]);
        //Line();
        return;
    }
    FOR(i,2,n){
        if( !taken[i] && ((v.size()==0 && p[1+i]) || (v.size()>0 && p[v[v.size()-1]+i])) ){
            taken[i]=1;
            v.push_back(i);
            call();
            taken[i]=0;
            v.pop_back();
        }
    }
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    FOR(i,0,34) p[i]=0;
    p[2]=1;p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=1;
    //FOR(i,0,34) if(p[i]) cout<<i<<" ";

    while(scanf("%ld",&n)==1){
        if(cs>1) Line();
        Case(cs);
        Line();
        if(n==1){
            printf("1\n");
            continue;
        }
        FOR(i,0,n) taken[i]=0;
        v.clear();
        call();
    }
    return 0;
}


