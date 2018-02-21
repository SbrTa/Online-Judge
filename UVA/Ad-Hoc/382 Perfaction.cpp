#include<stdio.h>
int main ()
{
    long int n,i,j=1,sum;
    for(;;)
    {
        scanf("%ld",&n);
        if(j==1)
            printf("PERFECTION OUTPUT\n");
        j++;
        if(n==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        sum=0;
        for(i=1;i<n;i++)
        {
            if(n%i==0)
                sum=sum+i;
            if(sum>n)
                break;
        }
        if(sum==n)
            printf("%5ld  PERFECT\n",n);
        else if(sum<n)
            printf("%5ld  DEFICIENT\n",n);
        else
            printf("%5ld  ABUNDANT\n",n);
    }
    return 0;
}
