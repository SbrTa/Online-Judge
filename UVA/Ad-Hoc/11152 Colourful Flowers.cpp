#include<stdio.h>
#include<math.h>
#define pi acos(-1)

int main()
{
    double a,b,c,r,R,s,rose,violet,sunflower,abc;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        s=(a+b+c)/2;
        abc=sqrt(s*(s-a)*(s-b)*(s-c));
        r=abc/s;
        R=(a*b*c)/(4*abc);
        rose=pi*r*r;
        violet=abc-rose;
        sunflower=(pi*R*R)-abc;
        printf("%.4lf %.4lf %.4lf\n",sunflower,violet,rose);
    }
    return 0;
}
