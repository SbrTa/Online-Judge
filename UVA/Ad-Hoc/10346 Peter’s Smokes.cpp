#include<stdio.h>
int main()
{
    long long int n,k,r,m,sum;
    while(scanf("%lld%lld",&n,&k)==2)
    {
        sum=n;
        go:
            r=n%k;
            m=n/k;
            sum=sum+m;
            n=m+r;
        if(n>=k)
            goto go;
        printf("%lld\n",sum);
    }
    return 0;
}
