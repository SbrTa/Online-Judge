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

char ss[33];
int taken[33],n,m,l;
vector<char>p,s;

void call()
{
    if(p.size()==l){
        FOR(i,0,l-1) cout<<p[i];
        cout<<endl;
        return;
    }
    FOR(i,0,n-1){
        //cout<<i<<endl;
        if(!taken[i] && (p.size()==0 || s[i]>=p[p.size()-1])){
        //if(!taken[i]){
            taken[i]=1;
            p.push_back(s[i]);
            call();
            p.pop_back();
            taken[i]=0;
            while(s[i+1]==s[i]) i++;
        }
    }
}

int main()
{
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1;
    long a,b,i,j;
    while(cin>>ss){
        scanf("%ld",&l);
        n=strlen(ss);
        mset(taken,0);
        s.clear();
        p.clear();
        for(i=0;i<n;i++)    s.push_back(ss[i]);
        sort(s.begin(),s.end());
        call();
    }
    return 0;
}
