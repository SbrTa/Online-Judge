#include<stdio.h>
int main()
{
    long int m,n,count,count1,i,j,temp;
    while(scanf("%ld %ld",&m,&n)==2)
    {
        printf("%ld %ld ",m,n);
        count1=0;
        if(m>n)
        {
            temp=m;
            m=n;
            n=temp;
        }

        for(i=m; i<=n; i++)
        {
            j=i;
            count=1;
            while(j>1)
            {

                if(j%2==0)
                    j=j/2;
                else
                    j=3*j+1;
                count++;
            }
            if(count>=count1)
                count1=count;
        }
        printf("%ld\n",count1);
    }
    return 0;
}
