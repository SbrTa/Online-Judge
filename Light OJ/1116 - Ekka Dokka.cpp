#include<stdio.h>
int main()
{
    long long int w,T,t,i,r,d,count;
    scanf("%lld",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%lld",&w);
        count=0;
        for(i=2; i<=w/2+1; i=i+i)
        {
            r=w%i;
            d=w/i;
            if(r==0&&d%2==1)
            {
                printf("Case %lld: %lld %lld\n",t,d,i);
                count=1;
                break;
            }
            if(count==1)
                break;
        }
        if(count==0)
            printf("Case %lld: Impossible\n",t);
    }
    return 0;
}
