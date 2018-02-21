#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
struct line
{
    long x1,y1,x2,y2;
}ln[100000];

bool srt(line a, line b)
{
    long aa = min(a.y1,a.y2);
    long bb = min(b.y1,b.y2);
    if(aa>bb) return true;
    return false;
}

long cros(long x1, long y1, long x2, long y2, long x3, long y3)
{
    return ( (x1*y2)+(x2*y3)+(x3*y1)-(x3*y2)-(x2*y1)-(x1*y3) );
}

int main()
{
    long test,cs=1,i,j,nln;
    scanf("%ld",&test);
    while(test--){
        if(cs==2) printf("\n");
        cs=2;
// input Line
        scanf("%ld",&nln);
        for(i=0;i<nln;i++){
            scanf("%ld%ld%ld%ld",&ln[i].x1,&ln[i].y1,&ln[i].x2,&ln[i].y2);
            if(ln[i].x1>ln[i].x2) swap(ln[i].x1,ln[i].x2),swap(ln[i].y1,ln[i].y2);
        }
        sort(ln,ln+nln,srt);
        //for(i=0;i<nln;i++) printf("%ld %ld %ld %ld\n",ln[i].x1,ln[i].y1,ln[i].x2,ln[i].y2);

// Process Line
        long sol[100000];
        for(i=0;i<=nln;i++) sol[i]=inf;

        for(i=0;i<nln;i++){
            if(sol[i]!=inf) continue;
            long x,y;
            long f=1,now=i;
            vector<long>v;
            while(f){
                v.push_back(now);
                f=0;
                if(ln[now].y1<ln[now].y2){
                    x=ln[now].x1;
                    y=ln[now].y1;
                }
                else{
                    x=ln[now].x2;
                    y=ln[now].y2;
                }
                //cout<<x<<" "<<y<<endl;
                for(j=now+1;j<nln;j++){
                    if(x>=ln[j].x1 && x<=ln[j].x2){
                        now=j;
                        f=1;
                        break;
                    }
                }
            }
            //cout<<endl;
            for(j=0;j<v.size();j++) sol[v[j]]=x;
        }
        //for(i=0;i<nln;i++) cout<<sol[i]<<endl;

// input water source & generate output
        long nw;
        scanf("%ld",&nw);
        while(nw--){
            long x,y,f=0;
            scanf("%ld%ld",&x,&y);
            for(i=0;i<nln;i++){
                if(x>=ln[i].x1 && x<=ln[i].x2){
                    long a1 = cros(x,y,ln[i].x1,ln[i].y1,ln[i].x2,ln[i].y2);
                    long a2 = cros(x,0,ln[i].x1,ln[i].y1,ln[i].x2,ln[i].y2);
                    if( (a1>=0&&a2>=0) || (a1<=0&&a2<=0) );
                    else{
                        f=1;
                        //cout<<a1<<" "<<a2<<endl;
                        printf("%ld\n",sol[i]);
                        break;
                    }
                }
            }
            if(f==0) printf("%ld\n",x);
        }
    }
    return 0;
}
