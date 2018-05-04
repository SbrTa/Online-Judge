#include<stdio.h>

int main()
{
    int T,t,n,k,p,i,j;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        scanf("%d%d%d",&n,&k,&p);
        j=k;
        for(i=1; i<=p; i++)
        {
            j++;
            if(j>n)
                j=1;
        }
        printf("Case %d: %d\n",t,j);
    }
    return 0;
}
