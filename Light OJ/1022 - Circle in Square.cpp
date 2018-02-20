#include<stdio.h>
#define pi 3.1415926535897932384626433832795
int main ()
{
    int t, i;
    scanf("%d", &t);
    for (i=1;i<=t;i++)
    {
        double r;
        scanf("%lf",&r);
        double a, b;
        a=pi*r*r;
        b=4*r*r;
        printf("Case %d: %.2f\n",i,b-a);
    }
    return 0;
}
