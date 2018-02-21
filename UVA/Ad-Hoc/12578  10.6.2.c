#include<stdio.h>
#include<math.h>
#define pi acos(-1)
int main()
{
    int T,t;
    double len,width,radius,red,green;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lf",&len);
        width=6*(len/10);
        radius=2*(len/10);
        red=pi*radius*radius;
        green=(len*width)-red;
        printf("%.2lf %.2lf\n",red,green);
    }
    return 0;
}
