#include<stdio.h>
#define max 200000000
unsigned long long int a[max];
int main()
{
    long long int n,m,count,i,j,r;
    while(scanf("%lld %lld",&n,&m)==2)
    {
        if(n<2||m<2||n<m)
        {
            printf("Boring!\n");
            continue;
        }
        count=0;
        i=0;
        while(1)
        {
            a[i]=n;
            if(n==1)
                break;
            r=n%m;
            if(r==0)
            {
                n=n/m;
                i++;
            }
            else
            {
                count=1;
                break;
            }
        }
        if(count==1)
            printf("Boring!\n");
        else
        {
            printf("%lld",a[0]);
            for(j=1; j<=i; j++)
                printf(" %lld",a[j]);
            printf("\n");
        }
    }
    return 0;
}
