#include<stdio.h>
int main()
{
    long long int T,t,n,m,result;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld",&n,&m);
        result=n/2*m;
        printf("Case %lld: %lld\n",t,result);
    }
    return 0;
}
