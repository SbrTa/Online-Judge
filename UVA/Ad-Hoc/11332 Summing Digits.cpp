#include<stdio.h>
int main()
{
    long long int n,r,sum,a;
    for(;;)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
sss :   sum=0;
        while(n!=0)
        {
            r=n%10;
            sum=sum+r;
            n=n/10;
        }
        n=sum;
        if(n>9)
            goto sss;
        printf("%lld\n",n);
    }
    return 0;
}
