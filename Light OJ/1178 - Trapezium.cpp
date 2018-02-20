#include<stdio.h>
#include<math.h>
int main()
{
    int T,t;
    double a,b,c,d;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        double s,area,e,abcd,h;
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        e=a-c;
        if(e<0)
            e=e*(-1);
        s=(b+d+e)/2;
        area=sqrt(s*(s-b)*(s-d)*(s-e));
        h=2*area/e;
        abcd=.5*(a+c)*h;
        printf("Case %d: %.10lf\n",t,abcd);
    }
    return 0;
}
