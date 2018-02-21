#include<stdio.h>
#include<math.h>
int main()
{
    double a,b,c,s,r;
    while(scanf("%lf%lf%lf",&a,&b,&c)==3)
    {
        if(a==0||b==0||c==0)
            r=0;
        else
        {
            s=(a+b+c)/2;
            r=sqrt(s*(s-a)*(s-b)*(s-c))/s;
        }
        printf("The radius of the round table is: %.3lf\n",r);
    }
    return 0;
}
