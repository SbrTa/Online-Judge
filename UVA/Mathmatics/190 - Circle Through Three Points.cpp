#include<bits/stdc++.h>
using namespace std;
#define inf 100005
#define LL long long

double distance(double ax, double ay, double bx, double by)
{
    return sqrt(((ax-bx)*(ax-bx))+((ay-by)*(ay-by)));
}

int main()
{
    double ax,ay,bx,by,cx,cy,x,y;

    while(scanf("%lf%lf",&ax,&ay)==2){
        scanf("%lf%lf",&bx,&by);
        scanf("%lf%lf",&cx,&cy);

        double ab = distance(ax,ay, bx,by);
        double ac = distance(ax,ay, cx,cy);
        double bc = distance(bx,by, cx,cy);
        double s = (ab+ac+bc)/2.0;
        double abc = sqrt(s*(s-ab)*(s-ac)*(s-bc));
        double r = (ab*ac*bc)/(4*abc);

        double a1,b1,c1;
        double a2,b2,c2;
        double a3,b3,c3;

        a1 = 2*ax - 2*bx;
        b1 = 2*ay - 2*by;
        c1 = bx*bx + by*by - ax*ax - ay*ay;

        a2 = 2*ax - 2*cx;
        b2 = 2*ay - 2*cy;
        c2 = cx*cx + cy*cy - ax*ax - ay*ay;

        double aa1=a1,aa2=a2;
        a1 = a1*aa2;
        b1 = b1*aa2;
        c1 = c1*aa2;

        a2 = a2*aa1;
        b2 = b2*aa1;
        c2 = c2*aa1;

        if(a1==a2){
            a3 = a1-a2;
            b3 = b1-b2;
            c3 = c1-c2;
        }
        else{
            a3 = a1+a2;
            b3 = b1+b2;
            c3 = c1+c2;
        }

        y = c3/b3;
        x = (c1-(b1*y))/a1;
        //printf("%.3lf %.3lf\n",x,y);


        // print 1st equation
        char ch1='+',ch2='+';
        if(x<0){
            x *= (-1);
            ch1='-';
        }
        if(y<0){
            y *= (-1);
            ch2='-';
        }
        printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n",ch1,x,ch2,y,r);

        //print 2nd equation
        char ch3='+';
        double f = (x*x) + (y*y) - (r*r);
        if(f<0){
            f *= (-1);
            ch3='-';
        }
        printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n",ch1,2*x,ch2,2*y,ch3,f);
    }
    return 0;
}
//7.0 -5.0 -1.0 1.0 0.0 -6.0
//1.0 7.0 8.0 6.0 7.0 -2.0

