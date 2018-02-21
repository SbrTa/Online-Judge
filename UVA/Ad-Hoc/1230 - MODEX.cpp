#include<stdio.h>

long long square(long long n)
{
    return (n*n);
}

long long bigmod(long long b, long long p, long long m)
{
    if (p==0)
        return 1;
    else if (p%2==0)  //(p%2 == 0) or P == even number
        return  square(bigmod(b,p/2,m))%m;
    else
        return ((b % m)*bigmod(b,p-1,m))%m;
}

int main()
{
    long long b,p,m,r,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&b,&p,&m);
        r=bigmod(b,p,m);
        printf("%lld\n",r);
    }
    scanf("%lld",&t);
    return 0;
}
