#include<stdio.h>

int main()
{
    long long a,b,term,t=1,n;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        if(a<0&&b<0)
            break;
        n=a;
        term=0;
        for(;;)
        {
            if(a>b)
                break;
            term++;
            if(a==1)
                break;
            if(a%2==0)
                a/=2;
            else
                a=a*3+1;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",t,n,b,term);
        t++;
    }
    return 0;
}
