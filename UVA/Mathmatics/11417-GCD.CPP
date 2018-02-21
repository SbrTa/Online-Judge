#include<stdio.h>
int main()
{
    int n,i,j,a,b,r,sum;
    for(;;)
    {
        sum=0;
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=1; i<n; i++)
            for(j=i+1; j<=n; j++)
            {
                r=1;
                a=i;
                b=j;
                while(r!=0)
                {
                    r=a%b;
                    a=b;
                    b=r;

                }
                sum=sum+a;
            }
        printf("%d\n",sum);
    }
    return 0;
}
