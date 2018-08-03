#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    LL r,n,tc=1,i;
    while(cin>>r>>n){
        if(r==0 && n==0) break;
        printf("Case %lld: ",tc++);
        LL f=1;
        for(i=0;i<=26;i++){
            LL can = n + (n*i);
            if(can>=r){
                printf("%lld\n",i);
                f=0;
                break;
            }
        }
        if(f)printf("impossible\n");
    }
    return 0;
}
