#include<stdio.h>
int main()
{
    int T,t,n,m,M,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        for(M=1;M<=m;M++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=i;j++)
                    printf("%d",i);
                printf("\n");
            }
            for(i=n-1;i>=1;i--)
            {
                for(j=1;j<=i;j++)
                    printf("%d",i);
                printf("\n");
            }
            if(M<m)
                printf("\n");
        }
        if(t<T)
            printf("\n");
    }
    return 0;
}
