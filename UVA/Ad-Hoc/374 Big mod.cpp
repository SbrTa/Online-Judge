#include<stdio.h>

long square(long n)
{
    return (n*n);
}

long bigmod(long b, long p, long m)
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
    long b,p,m,r;
    while(scanf("%ld%ld%ld",&b,&p,&m)==3)
    {
        r=bigmod(b,p,m);
        printf("%ld\n",r);
    }
    return 0;
}
