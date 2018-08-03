#include<bits/stdc++.h>
using namespace std;
#define LL long long

LL x[500000+5];

int main()
{
    LL n,i,j;
    for(n=1;n<=500000;n++){
        LL p=1;
        for(i=0;i<=20;i++){
            if(p*2>n){
                x[n] = n-p;
                break;
            }
            else p=p*2;
        }
    }
    while(cin>>n && n>0){
        if(x[n]) printf("%lld\n",x[n]*2);
        else printf("%lld\n",n);
    }
    return 0;
}
