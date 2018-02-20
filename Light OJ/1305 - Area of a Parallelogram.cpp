#include<stdio.h>
#include<math.h>
int main()
{
    static long long T,t,x1,x2,x3,x4,y1,y2,y3,y4;
    double a,b,c,area,s;
    scanf("%ld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld%lld%lld%lld%lld%lld",&x1,&y1,&x2,&y2,&x3,&y3);
        x4=x1+x3-x2;
        y4=y1+y3-y2;
        a=(double)sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        b=(double)sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
        c=(double)sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        s=(a+b+c)/2;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        printf("Case %lld: %lld %lld %.0lf\n",t,x4,y4,2*area);
    }
    return 0;
}
