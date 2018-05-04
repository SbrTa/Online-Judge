#include<stdio.h>

int main()
{
    int T,t,n,k,p,j;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d%d",&n,&k,&p);
        j=k+p;
        while(j>n)
            j=j-n;
        printf("Case %d: %d\n",t,j);
    }
    return 0;
}
