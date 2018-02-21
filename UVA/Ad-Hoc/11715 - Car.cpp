#include<stdio.h>
#include<math.h>
int main()
{
    double n,u,v,s,a,t,x,y,z;
    long int i;
    for(i=1;;i++)
    {
        scanf("%lf",&n);
        if(n==0)
            break;
        scanf("%lf %lf %lf",&x,&y,&z);
        if(n==1)
        {
            u=x;v=y;t=z;
            a=(v-u)/t;
            s=(v*v-u*u)/(2*a);
            printf("Case %ld: %.3lf %.3lf\n",i,s,a);
        }
        if(n==2)
        {
            u=x;v=y;a=z;
            t=(v-u)/a;
            s=(u*t)+(.5*a*t*t);
            printf("Case %ld: %.3lf %.3lf\n",i,s,t);
        }
        if(n==3)
        {
            u=x;a=y;s=z;
            v=sqrt((u*u)+(2*a*s));
            t=(v-u)/a;
            printf("Case %ld: %.3lf %.3lf\n",i,v,t);
        }
        if(n==4)
        {
            v=x;a=y;s=z;
            u=sqrt((v*v)-(2*a*s));
            t=(v-u)/a;
            printf("Case %ld: %.3lf %.3lf\n",i,u,t);
        }
    }
    return 0;
}
