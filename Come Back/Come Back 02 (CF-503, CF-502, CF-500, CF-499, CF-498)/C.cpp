#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define x first
#define y second
LL a[200005];

int main()
{
    LL n,d,i,j,t=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        t+=a[i];
    }
    if(n==1){
        printf("0\n");
        return 0;
    }

    LL x=0,y;
    LL xend,ystart;
    for(i=0;i<n;i++){
        x+=a[i];
        xend=i;
        if(x>t/2){
            x-=a[i];
            xend--;
            break;
        }
    }
    y = t-x;
    ystart=xend+1;
    //cout<<t<<" "<<x<<" "<<y<<endl;
    //cout<<xend<<" "<<ystart<<endl;

    for(i=ystart,j=xend;i<n && j>=0;){
        if(y==x){
            printf("%lld\n",x);
            return 0;
        }

        if(y>x){
            y-=a[i];
            i++;
        }
        if(x>y){
            x-=a[j];
            j--;
        }
    }
    printf("0\n");
    return 0;
}
