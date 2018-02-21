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
#define inf 33000
#define mod 10000007
#define MX 111
#define PI 2*acos(0.0)
using namespace std;

vector<long>p,d;
bool chk[inf+2];

void prime()
{
    long i,j;
    for(i=3;i*i<=inf;i+=2){
        if(!chk[i]){
            for(j=i*i;j<=inf;j+=i+i)
                chk[j]=true;
        }
    }
    chk[1]=true;
    p.push_back(2);
    for(i=3;i<=inf;i+=2) if(!chk[i]) p.push_back(i);

}

void divisor()
{
    long i,j,n,m;
    d.push_back(0); //0
    d.push_back(1); //1
    for(m=2;m<=inf;m++){
        n=m;
        long div=1;
        for(i=0;;i++){
            if(n==1) break;
            long cnt=0;
            while(n%p[i]==0){
                n=n/p[i];
                cnt++;
            }
            div=div*(cnt+1);
        }
        d.push_back(div);
    }
}

int main()
{
    prime();
    //cout<<p.size()<<endl;
    divisor();
    //cout<<d.size()<<endl;
    //freopen("A.txt", "r", stdin);
    //freopen("A.out.txt", "w", stdout);
    long test,cs=1,i,j;
    long n,m,a,b;
    inL(test);
    while(test--){
        m=0;
        inL2(a,b);
        for(n=a;n<=b;n++){
            if(d[n]==2 || (d[n]%2 && !chk[d[n]])){
                if(m>0) printf(" ");
                printf("%ld",n);
                m++;
            }
        }
        if(!m) printf("-1");
        puts("");
    }
    return 0;
}


