#include<stdio.h>
#include<math.h>
int main()
{
    long int n,a,b,i,j,count;
    for(;;)
    {
        count=0;
        scanf("%ld",&n);
        if(n==0)    break;
        b=(int)sqrt(n);
        for(i=1;i<=b;i++)
        {
            for(j=0;j<=i;j++)
            {
                if(i*i*i-j*j*j==n)
                    {printf("%ld %ld\n",i,j);    count++;    break;}
            }
            if(count==1)    break;
        }
        if(count==0)    printf("No solution\n");
    }
    return 0;
}
