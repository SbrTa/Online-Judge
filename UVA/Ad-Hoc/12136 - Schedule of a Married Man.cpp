#include<stdio.h>
#include<string.h>

int main()
{
    int h1,m1,h2,m2,hh1,mm1,hh2,mm2,T,t,stw,enw,stm,enm;
    char c;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d:%d",&h1,&m1);
        scanf("%d:%d",&h2,&m2);
        scanf("%d:%d",&hh1,&mm1);
        scanf("%d:%d",&hh2,&mm2);
        stw=h1*60+m1;
        enw=h2*60+m2;
        stm=hh1*60+mm1;
        enm=hh2*60+mm2;
        if(stm>enw||stw>enm)
            printf("Case %d: Hits Meeting\n",t);
        else
            printf("Case %d: Mrs Meeting\n",t);
    }
    return 0;
}
