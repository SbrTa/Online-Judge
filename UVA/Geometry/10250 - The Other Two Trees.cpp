#include<bits/stdc++.h>
using namespace std;
#define D double

int main()
{
    D x1,y1,x3,y3;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x3,&y3)==4){
        D midx = (x1+x3) / 2;
        D midy = (y1+y3) / 2;
        D difx = x1 - midx;
        D dify = y1 - midy;
        D x2 = midx + dify;
        D y2 = midy - difx;
        D x4 = midx - dify;
        D y4 = midy + difx;
        printf("%.10lf %.10lf %.10lf %.10lf\n",x2,y2,x4,y4);
    }
    return 0;
}
