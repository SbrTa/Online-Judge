#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,x,y;
    for(;;)
    {
        scanf("%d%d",&a,&b);
        if(a==-1&&b==-1)
            break;
        x=abs(a-b);
        if(a<b)
            y=a+100-b;
        else
            y=b+100-a;
        if(x<y)
            printf("%d\n",x);
        else
            printf("%d\n",y);
    }
    return 0;
}
