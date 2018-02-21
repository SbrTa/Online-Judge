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

long par[10000];
double a[10000],b[10000];

long Parent(long r){
    if(par[r]==r) return r;
    return par[r] = Parent(par[r]);
}

double dist(long i, long j){
    double r = sqrt( ((a[i]-a[j])*(a[i]-a[j])) + ((b[i]-b[j])*(b[i]-b[j])) );
    return r;
}

int main()
{
    long test,cs=1,n,i,j;
    double d;
    inL(test);
    while(test--){
        inL(n);
        inD(d);
        for(i=0;i<n;i++){
            inD(a[i]);
            inD(b[i]);
        }
        long nn=n;
        for(i=0;i<=n;i++)
            par[i]=i;
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(dist(i,j)<=d){
                    long u = Parent(i);
                    long v = Parent(j);
                    if(u!=v){
                        par[u]=v;
                        nn--;
                    }
                }
            }
        }
        printf("Case %ld: %ld\n",cs++,nn);
    }

    return 0;
}

