#include<stdio.h>
int main()
{
long long int T,t,s,d,x,y;
scanf("%lld",&T);
for(t=1;t<=T;t++)
{
    scanf("%lld%lld",&s,&d);
    if(s>=d)
    {
        if((s+d)%2==1||(s-d)%2==1)
            printf("impossible\n");
        else
        {
            x=(s+d)/2;
            y=(s-d)/2;
            printf("%lld %lld\n",x,y);
        }
    }
    else
        printf("impossible\n");
}
return 0;
}
