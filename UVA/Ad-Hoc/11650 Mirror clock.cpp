#include<stdio.h>
int main()
{
    int T,t,hh,mm,mm2,hh2,m,h;
    char c;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        mm2=0;hh2=12;
        scanf("%d%c%d",&hh,&c,&mm);
        if(c==':')
        {
            if(mm>0)
            {
                mm2=mm2+60;
                hh++;
            }
            if(hh>=12)
                hh=hh-12;
            m=mm2-mm;
            h=hh2-hh;
            if(h<10&&m<10)
                printf("0%d%c0%d\n",h,c,m);
            else if(h<10&&m>=10)
                printf("0%d%c%d\n",h,c,m);
            else if(h>=10&&m<10)
                printf("%d%c0%d\n",h,c,m);
            else
                printf("%d%c%d\n",h,c,m);
        }
    }
    return 0;
}

