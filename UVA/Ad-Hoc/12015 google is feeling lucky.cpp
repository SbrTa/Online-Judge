#include<stdio.h>

int main()
{
    int T,t,rating[10],i,m;
    char url[12][105];
    scanf("%d",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        m=-1;
        for(i=0;i<10;i++)
        {
            scanf("%s %d",url[i],&rating[i]);
            if(rating[i]>m)
                m=rating[i];
        }
        printf("Case #%d:\n",t);
        for(i=0;i<10;i++)
        {
            if(rating[i]==m)
                printf("%s\n",url[i]);
        }
    }
    return 0;
}
