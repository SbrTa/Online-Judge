/*
we have to find nCr.
nCr = n! / {(n-r)! * r!}

since factorial of a number can be so huge,
so we have to use big mod algorithm.
if, A=n!  &  B=(n-r)!*r!
then, (A/B)%M=[(A%M)*{bigmod(B,M-2,M)%M}]%M
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll fact[1000005],M=1000003;


ll bigmod(ll b, ll p)
{
    if(p==1)
        return b;
    else if(p%2==0)
    {
        ll temp=bigmod(b,p/2);
        return (temp*temp)%M;
    }
    else
        return (b*bigmod(b,p-1))%M;
}


int main()
{
    ll T,t,n,r,i,down;

    fact[1]=1;
    for(i=2;i<=1000000;i++)
        fact[i]=(i*fact[i-1])%M;

    cin>>T;
    for(t=1;t<=T;t++)
    {
        cin>>n>>r;
        if(n<r)
        {
            printf("Case %lld: 0\n",t);
            continue;
        }
        if(r==0||n==r)
        {
            printf("Case %lld: 1\n",t);
            continue;
        }
        down=((fact[n-r]%M)*(fact[r]%M))%M;
        ll combination=(fact[n]*bigmod(down,M-2))%M;
        printf("Case %lld: %lld\n",t,combination);
    }
    return 0;
}
