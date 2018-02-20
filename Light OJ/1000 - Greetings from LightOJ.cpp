#include<stdio.h>
int main()
{
    int T,t,a,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",t,a+b);
    }
    return 0;
}
