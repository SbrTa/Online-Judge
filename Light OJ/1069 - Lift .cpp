#include<stdio.h>
int main()
{
    int T,t,m,n,time;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&m,&n);
        if(n>=m)
            time=19+(n*4);
        else
            time=19+(((m-n)+m)*4);
        printf("Case %d: %d\n",t,time);
    }
    return 0;
}
