#include<bits/stdc++.h>
using namespace std;
#define D double
#define inf 1000000000
struct line
{
    D x1,y1,x2,y2,r;
}ln[100000];

struct ans
{
    D x,r;
}sol[100000];

bool srt(line a, line b)
{
    if(a.x1<b.x1) return true;
    return false;
}

int main()
{
    long test,cs=1,i,j,nl;
    scanf("%ld",&test);
    while(test--){
        if(cs==2) printf("\n");
        cs=2;
        D mx=-inf;
        scanf("%ld",&nl);
        for(i=0;i<nl;i++){
            scanf("%lf%lf%lf%lf%lf",&ln[i].x1,&ln[i].y1,&ln[i].x2,&ln[i].y2,&ln[i].r);
            if(ln[i].x1>ln[i].x2){
                swap(ln[i].x1,ln[i].x2);
                swap(ln[i].y1,ln[i].y2);
            }
            if(ln[i].x2>mx) mx=ln[i].x2;
        }
        sort(ln,ln+nl,srt);
        long sl=1;
        D mn=ln[0].x1 , x, xx;
        sol[0].x=mn;
        sol[0].r=1.00;
        //cout<<mn<<endl;
        while(mn<mx){
            D rr = 1;
            x=mn+0.000000001;
            xx=inf;
//            v.push_back();
            for(i=0;i<nl;i++){
                if(ln[i].x1>=x){
                    if(ln[i].x1-mn<xx) xx=ln[i].x1-mn;
                    break;
                }
                if(ln[i].x1<x && ln[i].x2>=x){
                    rr=rr*ln[i].r;
                    if(ln[i].x2-mn<xx) xx=ln[i].x2-mn;
                }
            }
            //cout<<xx<<" "<<mn<<endl;
            mn+=xx;
            sol[sl].x=mn;
            sol[sl].r=rr;
            sl++;
        }
        printf("%ld\n",sl+1);
        printf("-inf %.3lf 1.000\n",sol[0].x);
        for(i=1;i<sl;i++) printf("%.3lf %.3lf %.3lf\n",sol[i-1].x,sol[i].x,sol[i].r);
        printf("%.3lf +inf 1.000\n",sol[sl-1].x);
    }
    return 0;
}
