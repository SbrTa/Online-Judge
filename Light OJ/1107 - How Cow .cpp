#include<stdio.h>
int main()
{
    int T,t,x1,x2,y1,y2,x,y,cow,i;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        scanf("%d",&cow);
        printf("Case %d:\n",t);
        for(i=1;i<=cow;i++)
        {
            scanf("%d %d",&x,&y);
            if((x>x1&&x<x2)&&(y>y1&&y<y2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
