#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#define inf 46345  //sqrt(2^31)
using namespace std;

bool chk[inf+5];
vector<long>prime;

void PRIME()
{
    long i,j;
    for(i=3;i<=inf;i+=2)
        chk[i]=true;
    for(i=3;i*i<=inf;i+=2)
    {
        if(chk[i]==true)
        {
            for(j=i*i;j<=inf;j+=i+i)
                chk[j]=false;
        }
    }
    prime.push_back(2);
    for(i=3;i<=inf;i+=2)
        if(chk[i]==true) prime.push_back(i);
    prime.push_back(inf);
}

long CountDivisor(long n)
{
    long i,d=1,cp=1;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        long pf=0;
        while(n%prime[i]==0)
        {
            pf++;
            n/=prime[i];
        }
        d*=(pf+1);
        if(pf) cp = cp * pow(prime[i],pf-1) * (prime[i]-1);
    }
    if(n>1)
    {
        d*=2;
        cp=cp*(n-1);
    }
    return d+cp-1;
}

int main()
{
    PRIME();
    long n,ans;
    while(scanf("%ld",&n)==1)
    {
        ans = CountDivisor(n);
        if(ans<=2) printf("0\n");
        else printf("%ld\n",n-ans);
    }
    return 0;
}
