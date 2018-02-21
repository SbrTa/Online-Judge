#include<stdio.h>
int main()
{
    long long int t,n,sum,a,b,c;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum=0;
        while(n--)
        {
            scanf("%lld%lld%lld",&a,&b,&c);
            sum=sum+(a*c);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
