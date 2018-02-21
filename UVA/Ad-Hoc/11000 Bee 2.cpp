#include<stdio.h>

int main()
{
    long long n,i,fibo[100000],sum[100000];
    while(scanf("%lld",&n)&&n>=0)
    {
        sum[0]=1;
        fibo[0]=0;
        fibo[1]=1;
        for(i=2;i<=n+1;i++)
            fibo[i]=fibo[i-1]+fibo[i-2];
        for(i=1;i<=n;i++)
            sum[i]=sum[i-1]+fibo[i+1];
        printf("%lld %lld\n",sum[n]-fibo[i],sum[n]);
    }
    return 0;
}
