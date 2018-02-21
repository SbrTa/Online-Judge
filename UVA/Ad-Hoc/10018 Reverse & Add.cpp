#include<stdio.h>

int main()
{
    long long int T,t,num,sum,sum2,i;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld",&num);
        sum=num;
        i=0;
        while(1)
        {
            sum2=0;
            while(num!=0)
            {
                sum2=sum2*10+num%10;
                num=num/10;
            }
            num=sum2;
            if(num==sum)
                break;
            else
            {
                sum=sum+num;
                num=sum;
                i++;
            }
        }
        printf("%lld %lld\n",i,num);
    }
    return 0;
}
