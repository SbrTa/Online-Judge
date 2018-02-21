#include<bits/stdc++.h>
using namespace std;
#define L long
#define D double
#define eps 10e-9

D area(D x1, D y1, D x2, D y2, D x3, D y3)
{
    return ( (x1*y2)+(x2*y3)+(x3*y1)-(x3*y2)-(x2*y1)-(x1*y3) );
}

int main()
{
    D ax1,ay1,ax2,ay2,bx1,by1,bx2,by2;
    L i,j,test;
    scanf("%ld",&test);
    printf("INTERSECTING LINES OUTPUT\n");
    while(test--){
        scanf("%lf%lf%lf%lf",&ax1,&ay1,&ax2,&ay2);
        scanf("%lf%lf%lf%lf",&bx1,&by1,&bx2,&by2);

        if( !area(ax1,ay1,ax2,ay2,bx1,by1) && !area(ax1,ay1,ax2,ay2,bx2,by2) ){
            printf("LINE\n");
            continue;
        }

        // m = (y2-y1) / (x2-x1)
        D m1 = (ay2-ay1)/(ax2-ax1);
        D m2 = (by2-by1)/(bx2-bx1);
        if(ax1==ax2) m1=90;
        if(bx1==bx2) m2=90;
        if(m1==m2){
            printf("NONE\n");
            continue;
        }

        // y = mx + c
        // c = y - mx
        D c1 = ay1 - (m1*ax1);
        D c2 = by1 - (m2*bx1);
        //cout<<c1<<" "<<c2<<endl;
        D x = (c2-c1) / (m1-m2);
        D y = (m1*x) + c1;
        //cout<<x<<" "<<y<<endl;
        //x+=eps;
        //y+=eps;
        if(m1==90&&m2==0){
            x=ax1,y=by1;
            printf("POINT %.2lf %.2lf\n",x,y);
        }
        else if(m2==90&&m1==0){
            x=bx1,y=ay1;
            printf("POINT %.2lf %.2lf\n",x,y);
        }
        else printf("POINT %.2lf %.2lf\n",x,y);
    }
    printf("END OF OUTPUT\n");
    return 0;
}

