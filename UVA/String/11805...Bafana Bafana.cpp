#include<stdio.h>


int main()
{

    int T,k,p,n,i,j;
    scanf("%d",&T);
    for (i=1; i<=T; i++)
    {
        scanf("%d%d%d",&n,&k,&p);


        int s=k;
        for( j=1; j<=p; j++)
        {
            s++;
            if(s>n)
                s=1;
        }

        printf("Case %d: %d\n",i,s);

    }

    return 0;
}
