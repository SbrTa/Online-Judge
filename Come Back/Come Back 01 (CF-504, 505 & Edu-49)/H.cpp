#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define inf 200000

LL up(LL n, LL d)
{
    if(n%d) return n/d + 1;
    return n/d;
}

int main()
{
    LL n,q,k,i,j,x,y;
    scanf("%lld%lld",&n,&q);

    LL a,b,as,bs;

    as=0;
    bs=up(n*n,2);
    a=up(n,2);
    b=n/2;


    while(q--){
        LL s;
        scanf("%lld%lld",&x,&y);
        if((x+y)%2==0)  if(n%2==0) s = as + ((x-1)*a) + up(y,2);
                        else s = as + (up(x-1,2)*a) + (((x-1)/2)*b) + up(y,2);
        else    if(n%2==0) s = bs + ((x-1)*b) + up(y,2);
                else s = bs + (up(x-1,2)*b) + (((x-1)/2)*a) + up(y,2);
        printf("%lld\n",s);
    }
    return 0;
}

