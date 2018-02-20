#include<stdio.h>
#include<math.h>

int main()
{
    int T,t;
    double Ox,Oy,Ax,Ay,Bx,By,pi=2*acos(0.0);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        double r,AB,alpha,theta,ans,b;
        scanf("%lf%lf%lf%lf%lf%lf",&Ox,&Oy,&Ax,&Ay,&Bx,&By);
        r=sqrt((Ax-Ox)*(Ax-Ox)+(Ay-Oy)*(Ay-Oy));
        AB=sqrt((Ax-Bx)*(Ax-Bx)+(Ay-By)*(Ay-By));
        b=AB/(2*r);
        alpha=acos(b)*180/pi;
        theta=180-(2*alpha);
        ans=pi*theta*r/180;
        printf("Case %d: %.8lf\n",t,ans);
    }
    return 0;
}
