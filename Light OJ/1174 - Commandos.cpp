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

#define inInt(n) scanf("%d",&n)
#define inLong(n) scanf("%ld",&n)
#define inLL(n) scanf("%lld",&n)
#define inFloat(n) scanf("%f",&n)
#define inDouble(n) scanf("%lf",&n)
#define inLD(n) scanf("%Lf",&n)
#define inStr(n) scanf("%s",n)
#define inChar(n) scanf("%c",&n)

#define pInt(n) printf("%d",n)
#define pLong(n) printf("%ld",n)
#define pLL(n) printf("%lld",n)
#define pFloat(n) printf("%f",n)
#define pDouble(n) printf("%lf",n)
#define pLD(n) printf("%Lf",n)
#define pStr(n) printf("%s",n)
#define pSpc() printf(" ")
#define Line() printf("\n")
#define Case(n) printf("Case %ld: ",n++)

#define INF 0x7f7f7f
#define MX 111
#define PI acos(-1.0)
using namespace std;

long v[111][111];

int main()
{
    long test,cs=1;
    long n,m,a,b,i,j,k;
    inLong(test);
    while(test--){
        inLong(n);
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                v[i][j] = (i==j)? 0:INF;
        inLong(m);
        while(m--){
            inLong(a);
            inLong(b);
            v[a][b]=1;
            v[b][a]=1;
        }

        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(i!=j)
                    v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
                }
            }
        }
        inLong(a);
        inLong(b);
        long mx=0;
        for(i=0;i<n;i++){
            if(v[a][i]+v[i][b] > mx)
                mx = v[a][i]+v[i][b];
        }
        Case(cs);
        pLong(mx);
        Line();
    }

    return 0;
}


/*
1
6
8
0 1
0 2
1 2
1 3
3 5
3 4
2 3
4 5
0 5

5*/
