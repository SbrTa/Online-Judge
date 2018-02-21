#include<stdio.h>
int main()
{
    int v,t,s=0;
    while(scanf("%d%d",&v,&t)==2)
    {
        if((-100<=v<=100)&&(0<=t<=200))
        {
            s=2*v*t;
            printf("%d\n",s);
        }
        else
            break;
    }
return 0;
}
