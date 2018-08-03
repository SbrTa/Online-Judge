#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    LL n;
    while(scanf("%lld",&n) && n>0){
        LL x,y,m,mx,mn;
        LL sq = sqrt(n);
        if(sq&1){
            mx = sq*sq + sq+1;
            mn = sq*sq - sq+1;
            if(n>=mn && n<=mx){
                ;
            }
            else{
                sq++;
                mx = sq*sq + sq;
                mn = sq*sq - sq+2;
            }
        }
        else{
            mx = sq*sq + sq;
            mn = sq*sq - sq+2;
            if(n>=mn && n<=mx){
                ;
            }
            else{
                sq++;
                mx = sq*sq + sq+1;
                mn = sq*sq - sq+1;
            }
        }
        if(sq&1){
            //cout<<"bijor"<<endl;
            if(sq*sq==n){
                y=sq;
                x=1;
            }
            else if(n>sq*sq){
                //cout<<"boro"<<endl;
                x = n - sq*sq;
                y = sq + 1;
            }
            else{
                //cout<<"choto"<<endl;
                x = sq*sq - n+1;
                y = sq;
            }
        }
        else{
            //cout<<"jor"<<endl;
            if(sq*sq==n){
                y=1;
                x=sq;
            }
            else if(n>sq*sq){
                //cout<<"boro"<<endl;
                y = n - sq*sq;
                x = sq + 1;
            }
            else{
                //cout<<"choto"<<endl;
                y = sq*sq - n+1;
                x = sq;
            }
        }
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
