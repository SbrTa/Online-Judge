#include<stdio.h>
int main()
{
    long int n,m,count,i,j,x,c,count1,temp;
    for(;;)
    {
        scanf("%ld %ld",&n,&m);
        if(n==0&&m==0)
            break;
        count1=0;
        if(n>m)
        {
            temp=n;
            n=m;
            m=temp;
        }
        for(i=n; i<=m; i++)
        {
            j=i;
            count=0;
            do
            {

                if(j%2==0)
                    j=j/2;
                else
                    j=3*j+1;
                count++;
            }while(j!=1);
            if(count>count1)
            {
                count1=count;
                c=i;
            }
        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",n,m,c,count1);
    }
    return 0;
}
