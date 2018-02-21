#include<stdio.h>

int main()
{
    long long i,j,ugly[1505];
    ugly[1]=1;

    for(i=2; i<=1500; i++)
    {
        ugly[i]=1000000000;
        for(j=1; j<=i; j++)
        {
            if(ugly[j]*2>ugly[i-1])
            {
                if(ugly[j]*2<ugly[i])
                    ugly[i]=ugly[j]*2;
            }
            else if(ugly[j]*3>ugly[i-1])
            {
                if(ugly[j]*3<ugly[i])
                    ugly[i]=ugly[j]*3;
            }
            else if(ugly[j]*5>ugly[i-1])
            {
                if(ugly[j]*5<ugly[i])
                    ugly[i]=ugly[j]*5;
            }
        }
    }
    for(i=1;i<=1500;i++)
        printf("%lld ",ugly[i]);
    puts("");
    printf("The 1500'th ugly number is %lld.\n",ugly[1500]);
    return 0;
}
