#include<stdio.h>
#include<math.h>
#define pi acos(-1)

int main()
{
    double x1,x2,x3,y1,y2,y3,a,b,c,r,s,result,abc;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)==6)
    {
        a=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
        b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
        c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
        s=(a+b+c)/2;
        abc=sqrt(s*(s-a)*(s-b)*(s-c));
        r=(a*b*c)/(4*abc);
        result=2*pi*r;
        printf("%.2lf\n",result);
    }
    return 0;
}
