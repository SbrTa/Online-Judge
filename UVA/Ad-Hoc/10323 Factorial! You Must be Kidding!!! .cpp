#include<stdio.h>

int main()
{
    long long int n,fact,i;
    while(scanf("%lld",&n)==1)
    {
        if(n>=0&&n<8)
            printf("Underflow!\n");
        else if(n>13)
            printf("Overflow!\n");
        else if(n>=8&&n<=13)
        {
            fact=1;
            for(i=1;i<=n;i++)
                fact*=i;
            printf("%lld\n",fact);
        }
        else
        {
            if(n&1)
                printf("Overflow!\n");
            else
                printf("Underflow!\n");
        }
    }
    return 0;
}
