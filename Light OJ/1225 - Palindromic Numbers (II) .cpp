#include<stdio.h>
int main()
{
long long int T,t,a,b,c,r;
scanf("%lld",&T);
for(t=1;t<=T;t++)
{
    scanf("%lld",&c);
    a=c;
    b=0;
    while(a!=0)
    {
    r=a%10;
    b=b*10+r;
    a=a/10;
    }
    if(c==b)
        printf("Case %lld: Yes\n",t);
    else
        printf("Case %lld: No\n",t);
}
return 0;
}
