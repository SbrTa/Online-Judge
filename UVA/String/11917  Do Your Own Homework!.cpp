#include<stdio.h>
#include<string.h>

int main()
{
    int T,t,n,m[105],d,i,j;
    char sub[105][25],s[25];
    scanf("%d",&T);
    getchar();
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%s%d",sub[i],&m[i]);
        }
        scanf("%d",&d);
        getchar();
        gets(s);
        printf("Case %d: ",t);
        j=0;
        for(i=0;i<n;i++)
        {
            if(strcmp(s,sub[i])==0)
            {
                if(m[i]<=d)
                    printf("Yesss\n");
                else if(m[i]<=(d+5))
                    printf("Late\n");
                else
                    printf("Do your own homework!\n");
                j=1;
                break;
            }
        }
        if(j==0)
            printf("Do your own homework!\n");
    }
    return 0;
}
