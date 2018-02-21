#include<stdio.h>
int main()
{
    int a1,a2,b1,b2,c1,c2,p,q,r;
    float x,y;
    while(scanf("%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2)==6)
    {
        if(a1==0&&a2==0&&b1==0&&b2==0&&c1==0&&c2==0)
            break;
        p=(a2*b1)-(a1*b2);
        if(p==0)
            printf("No fixed point exists.\n");
        else
        {
            q=(b1*c2)-(b2*c1);
            r=(c1*a2)-(c2*a1);
            x=(float)q/p;
            y=(float)r/p;
            printf("The fixed point is at %.2f %.2f.\n",x,y);
        }
    }
    return 0;
}
