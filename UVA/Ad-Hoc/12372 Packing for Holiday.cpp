#include<stdio.h>
int main()
{
    int T,t,a,b,c;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a<=20&&b<=20&&c<=20)
            printf("Case %d: good\n",t);
        else
            printf("Case %d: bad\n",t);
    }
    return 0;
}
