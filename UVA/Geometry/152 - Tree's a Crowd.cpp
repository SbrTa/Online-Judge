#include<bits/stdc++.h>
using namespace std;

long x[5555],y[5555],z[5555],d[15];

long dist(long i, long j)
{
    long a=x[i]-x[j];
    long b=y[i]-y[j];
    long c=z[i]-z[j];
    long r=sqrt(a*a + b*b + c*c);
    return r;
}

int main()
{
    long i,j,n=0;
    while(scanf("%ld%ld%ld",&x[n],&y[n],&z[n]) && x[n]+y[n]+z[n++]);
    n--;
    for(i=0;i<n;i++){
        long mn=10;
        for(j=0;j<n;j++){
            if(i==j) continue;
            long dd=dist(i,j);
            if(dd<mn) mn=dd;
        }
        if(mn<10) d[mn]++;
    }
    for(i=0;i<10;i++){
        printf("%4ld",d[i]);
    }
    printf("\n");
    return 0;
}
