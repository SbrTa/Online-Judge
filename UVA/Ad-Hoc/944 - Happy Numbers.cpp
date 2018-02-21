#include<bits/stdc++.h>
using namespace std;

long ans[99999+100]; //all zero

void pre()
{
    long i,n,m;
    ans[1]=1;
    for(m=2;m<=99999;m++){
        map<long,long>mp;
        n=m;
        long cnt=0,f=0;
        while(1){
            mp[n]=1;
            cnt++;
            long x=0;
            while(n!=0){
                long r=n%10;
                n=n/10;
                x=x+(r*r);
            }
            n=x;
            if(n==1){
                f=1;
                break;
            }
            if(ans[n]>0){
                cnt=cnt+ans[n]-1;
                f=1;
                break;
            }
            if(mp[n] || ans[n]==-1) break;
        }
        if(f==1) ans[m]=cnt+1;
        else ans[m]=-1;
    }
}

int main()
{
    pre();
    long l,h,i,cs=0;
    while(scanf("%ld %ld",&l,&h)==2)
    {
        if(cs) printf("\n");
        cs=1;
        for(i=l;i<=h;i++){
            if(ans[i]>0) printf("%ld %ld\n",i,ans[i]);
        }
    }
    return 0;
}
