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

long par[10000],flag[10000];

long Parent(long r){
    if(par[r]==r) return r;
    return par[r] = Parent(par[r]);
}

int main(){
    long test,cs=1;
    long n,m,a,b,i,j;
    inL(test);
    while(test--){
        inL(n);
        for(i=0; i<=n; i++)
            par[i]=i;
        long yes=0,no=0;
        char ch;
        getchar();

        while(inC(ch)==1 && isalpha(ch)){
            inL(a);
            inL(b);
            getchar();
        //cout<<ch<<endl;

            long u = Parent(a);
            long v = Parent(b);
            if(ch=='c'){
                if(u!=v)
                    par[u]=v;
            }
            else{
                if(u!=v) no++;
                else yes++;
            }
        }
        if(cs>1) pLine();
        printf("%ld,%ld\n",yes,no);
        cs=2;
    }
    return 0;
}
