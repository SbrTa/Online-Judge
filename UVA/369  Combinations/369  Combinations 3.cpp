#include<bits/stdc++.h>
using namespace std;

long long combin(long long n, long long r)
{
    long long combination=1,boro,choto,i,j;

    boro=(n-r>r)?n-r:r;
    choto=n-boro;

    for(i=1,j=boro+1; i<=choto; i++, j++)
        combination=combination*j/i;

    return combination;
}


int main()
{
    long long n,r;
    while(scanf("%lld%lld",&n,&r)==2)
    {
        if(n==0 && r==0) break;
        printf("%lld\n",combin(n,r));
    }
    return 0;
}
