#include<stdio.h>
int summing_digit(long long int n)
{
    int sum=0,r;
        while(n!=0)
        {
            r=n%10;
            sum=sum+r;
            n=n/10;
        }
        return sum;
}

int main()
{
    long long int n,a;
    for(;;)
    {
        scanf("%lld",&n);
        if(n==0)
            break;
        while(n>9)
        {
            n=summing_digit(n);
        }
        printf("%lld\n",n);
    }
    return 0;
}
