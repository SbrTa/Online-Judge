#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define mod 1000003
using namespace std;

long long square(long long x)
{
    return x*x;
}

long long  bigmod (long long b, long long p, long long m)
{
    if (p == 0)
        return 1;
    else if (p%2 == 0)
        return  square ( bigmod (b, p/2, m )) % m;   // square(x) = x * x
    else
        return ((b % m) * bigmod ( b, p-1, m )) % m;
}

long a[1000002];

int main()
{
    long long  test,cs=1;
    long long  n,r,i,j;
    scanf("%lld",&test);
    a[0]=1;
    for(i=1;i<=1000000;i++)
        a[i] = (a[i-1]*i) % mod;

    while(test--){
        scanf("%lld %lld",&n,&r);
        long long temp = ( a[r] * a[n-r] ) %mod;

        long long ans = (a[n] * bigmod(temp,mod-2,mod))%mod;

        printf("Case %lld: %lld\n",cs++,ans);
    }
    return 0;
}

