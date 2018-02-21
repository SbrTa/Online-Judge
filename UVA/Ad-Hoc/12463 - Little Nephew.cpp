#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,d,e;
    while(scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e)==5){
        if(a+b+c+d+e==0) break;
        long long ans = a*b*c*d*d*e*e;
        printf("%lld\n",ans);
    }
    return 0;
}
