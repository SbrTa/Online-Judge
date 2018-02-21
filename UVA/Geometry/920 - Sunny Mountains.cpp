#include<bits/stdc++.h>
using namespace std;
#define L long
#define D double

D xx,yy;

struct point
{
    D x,y;
}p[1000];

bool srt(point a, point b)
{
    if(a.x>b.x) return true;
    return false;
}

D distance(D x1, D y1, D x2, D y2)
{
    D r = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
    return r;
}

void intersect(D ax1, D ay1, D ax2, D ay2, D bx1, D by1, D bx2, D by2)
{
    if(bx1==bx2){
        xx = bx1;
        yy = ay1;
        return;
    }
    D m1 = 0;
    D m2 = (by2-by1)/(bx2-bx1);
    if(bx1==bx2) m2=90;

    D c1 = ay1 - (m1*ax1);
    D c2 = by1 - (m2*bx1);

    xx = (c2-c1) / (m1-m2);
    yy = (m1*ax1) + c1;
}

int main()
{
    L test,cs=1,i,j,n;
    scanf("%ld",&test);
    while(test--){
        scanf("%ld",&n);
        for(i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        sort(p,p+n,srt);
        //for(i=0;i<n;i++) cout<<p[i].x<<" "<<p[i].y<<endl;
        //continue;
        D x = p[0].x;
        D y = p[0].y;
        long ll=0;
        D s=0;
        for(i=0;i<n;i++){
            if(p[i].y<=y){
                ll++;
                continue;
            }
            if(ll==0){
                s += distance(x,y,p[i].x,p[i].y);
                x = p[i].x;
                y = p[i].y;
                continue;
            }
            intersect( x,y,0,y , p[i].x,p[i].y,p[i-1].x,p[i-1].y );
            s += distance(xx,yy,p[i].x,p[i].y);
            x = p[i].x;
            y = p[i].y;
            ll=0;
        }
        printf("%.2lf\n",s);
    }
    return 0;
}
