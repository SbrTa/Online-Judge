#include<stdio.h>

int main()
{
    long long int n,sum;
    while(scanf("%lld",&n)==1)
    {
        sum=((n*n*(n+1)*(n+1))/4);
        printf("%lld\n",sum);
    }
    return 0;
}
